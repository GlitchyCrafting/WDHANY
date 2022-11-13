#[macro_use] extern crate rocket;

use rocket_dyn_templates::{Template, context};
use rocket::fs::{FileServer, relative};
use rocket::http::{CookieJar, Cookie};
use rocket::response::Redirect;

#[get("/")]
fn index() -> Template {
    Template::render("home", context!{})
}

#[get("/<id>")]
fn lesson(id: i32) -> Template {
    Template::render("lesson", context!{ id: id, name: "One", code: "tsaneinh", content: "tsadtrdtsrdtrdtrsdhdtrf", answer: "" })
}

#[get("/write/<id>")]
fn write(cookies: &CookieJar<'_>, id: i32) -> Redirect {
    cookies.add(Cookie::new("lesson", id.to_string()));
    Redirect::to(uri!(lesson(id + 1)))
}

#[get("/read")]
fn read(cookies: &CookieJar<'_>) -> Redirect {
    let cookie = cookies.get("lesson")
        .map(|c| format!("{}", c.value()))
        .unwrap()
        .parse::<i32>()
        .unwrap();
    println!("{:?}", cookie);
    Redirect::to(uri!(lesson(cookie)))
}

#[launch]
fn rocket() -> _ {
    rocket::build()
        .mount("/", routes![index, lesson, write, read])
        .mount("/static", FileServer::from(relative!("static")))
        .attach(Template::fairing())
}
