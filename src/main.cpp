// CROW Libs
#define CROW_MAIN
#include "crow.h"
#include "crow/middlewares/cookie_parser.h"

// Std Libs
#include <stdio.h>
#include <filesystem>

// SQLite
#include "sqlite_modern_cpp.h"

struct Lesson {
  int id;
  std::string name;
  std::string content;
  std::string code;
  std::string answer;
};

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

//  db << "insert into lesson (name,content,code,answer) values (?,?,?,?);"
//    << u"Some Lesson"
//    << u"Some Content"
//    << u"Some Code"
//    << u"Some Answer";

int main () {
  // initialize everything
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

  // Set the port, use multiple threads, run the app
  app.port(3000).multithreaded().run();

  return 0;
}
