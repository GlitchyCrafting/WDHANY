#[macro_use] extern crate rocket;

use rocket_dyn_templates::{Template, context};
use rocket::fs::{FileServer, relative};
use rocket::http::{CookieJar, Cookie};
use rocket::response::Redirect;
use rocket::Request;
use rocket::time::Duration;

use rusqlite::{Connection, Result};

#[derive(Debug)]
struct Lesson {
    name: String,
    content: String,
    code: String,
    answer: String
}

fn get_lesson(id: i64) -> Result<Lesson, rusqlite::Error> {
    let db = Connection::open("./db.sqlite")?;
    let lesson = db.query_row(
        "SELECT name,content,code,answer FROM lesson WHERE _id = ?",
        [id],
        |row| {
            let name_d = row.get(0);
            let content_d = row.get(1);
            let code_d = row.get(2);
            let answer_d = row.get(3);

            Ok(Lesson {
                name: name_d.unwrap(),
                content: content_d.unwrap(),
                code: code_d.unwrap(),
                answer: answer_d.unwrap(),
            })
        }
        );

    Ok(lesson.unwrap())
}

#[catch(404)]
fn not_found(req: &Request) -> Template {
    Template::render("404", context!{ request: req.uri() })
}

#[catch(500)]
fn internal_server_error(req: &Request) -> Template {
    Template::render("500", context!{ request: req.uri() })
}

#[get("/")]
fn index() -> Template {
    Template::render("home", context!{})
}

#[get("/<id>")]
fn lesson(id: i64) -> Option<Template> {

    let lesson_d = get_lesson(id).ok().unwrap();

    Some(Template::render("lesson", context!{
        id: id,
        name: lesson_d.name,
        content: lesson_d.content,
        code: lesson_d.code,
        answer: lesson_d.answer
    }))
}

#[get("/write/<id>")]
fn write(cookies: &CookieJar<'_>, id: i64) -> Redirect {
    let mut c = Cookie::new("lesson", {id + 1}.to_string());
    c.set_max_age(Duration::weeks(104));
    assert_eq!(c.max_age(), Some(Duration::weeks(104)));
    cookies.add(c);
    Redirect::to(uri!(lesson(id + 1)))
}

#[get("/read")]
fn read(cookies: &CookieJar<'_>) -> Redirect {
    let cookie = cookies.get("lesson")
        .map(|c| format!("{}", c.value()))
        .unwrap()
        .parse::<i64>()
        .unwrap();
    Redirect::to(uri!(lesson(cookie)))
}

#[launch]
fn rocket() -> _ {
    rocket::build()
        .mount("/", routes![index, lesson, write, read])
        .mount("/static", FileServer::from(relative!("static")))
        .register("/", catchers![not_found, internal_server_error])
        .attach(Template::fairing())
}
