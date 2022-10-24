// CROW Libs
#include "crow/common.h"
#include "crow/http_response.h"
#define CROW_MAIN
#include "crow.h"
#include "crow/middlewares/cookie_parser.h"

// Std Libs
#include <stdio.h>
#include <filesystem>

// SQLite
#include "sqlite_modern_cpp.h"

void sqlInit(sqlite::database db) {
  db <<
    "create table if not exists lesson ("
    "   _id integer primary key autoincrement not null,"
    "   name text,"
    "   content text,"
    "   code text,"
    "   answer text"
    ");";
}

crow::response redirect(std::string location) {
  crow::response res;
  res.redirect(location);
  std::cout << location;
  return res;
}

int main () {
  // Initialize everything
  crow::App<crow::CookieParser> app;
  sqlite::database db("db.sqlite");
  sqlInit(db);

  // Define the root endpoint
  // TODO make a proper landing page
  CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)
    ([](){
      auto page = crow::mustache::load("home.html");
      return page.render();
    });

  // Define the lesson endpoint
  // TODO Redirect for writing a new cookie when correct
  CROW_ROUTE(app, "/lesson/<int>").methods(crow::HTTPMethod::POST, crow::HTTPMethod::GET)
    ([&db](const crow::request& req, int id){

      std::string name;
      std::string content;
      std::string code;
      std::string answer;

      db << "select name,content,code,answer from lesson where _id = ? ;"
      << id
      >>  tie(name, content, code, answer);

      crow::mustache::context ctx({
        {"id", id},
        {"name", name},
        {"content", content},
        {"code", code},
        {"answer", answer}});

      auto page = crow::mustache::load("lesson.html");
      return page.render(ctx);
    });

  // Read Cookies
  CROW_ROUTE(app, "/read").methods(crow::HTTPMethod::POST, crow::HTTPMethod::GET)
    ([&](const crow::request& req){
      auto& ctx = app.get_context<crow::CookieParser>(req);
      auto value = ctx.get_cookie("LessonNum");
      std::cout << "/lesson/" + value;
      return redirect("/lesson/" + value);
      //return value;
    });

  // Write Cookies
  CROW_ROUTE(app, "/write/<int>").methods(crow::HTTPMethod::POST, crow::HTTPMethod::GET)
    ([&](const crow::request& req, int id){
      id = id + 1;
      auto& ctx = app.get_context<crow::CookieParser>(req);
      ctx.set_cookie("LessonNum", std::to_string(id)).path("/").max_age(100000000).same_site(crow::CookieParser::Cookie::SameSitePolicy::None);
      return redirect("/lesson/" + std::to_string(id));
    });

  // Set the port, use multiple threads, run the app
  app.port(3000).multithreaded().run();

  return 0;
}
