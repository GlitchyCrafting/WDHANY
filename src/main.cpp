// CROW Libs
#define CROW_MAIN
#include "crow.h"
#include "crow/middlewares/cookie_parser.h"

// Std Libs
#include <stdio.h>
#include <filesystem>

// SQLite_ORM
#include "include/sqlite_orm.h"

struct Lesson {
  int id;
  std::string name;
  std::string content;
  std::string code;
  std::string answer;
};

auto sqlinit() {
  auto database = sqlite_orm::make_storage("db.sqlite",
                                  sqlite_orm::make_table("LESSONS",
                                                         sqlite_orm::make_column("ID", &Lesson::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
                                                         sqlite_orm::make_column("NAME", &Lesson::name),
                                                         sqlite_orm::make_column("CONTENT", &Lesson::content),
                                                         sqlite_orm::make_column("CODE", &Lesson::code),
                                                         sqlite_orm::make_column("ANSWER", &Lesson::answer)));
  database.sync_schema();
  return database;
}

int main () {
  // initialize everything
  crow::App<> app;
  auto database = sqlinit();

  // Define the root endpoint
  // TODO make a proper landing page
  CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)
    ([](){
      return "There is not a homepage yet.";
    });

  // Define the lesson endpoint
  // TODO IN-PROGRESS make a lessons page that grabs a lesson from the db
  CROW_ROUTE(app, "/lesson/<int>").methods(crow::HTTPMethod::POST, crow::HTTPMethod::GET)
    ([](const crow::request& res, int id) {
      crow::mustache::context ctx({
          {"id", id},
          {"name", "Example Title"},
          {"content", "Example Content"},
          {"code", "Some Example Code"},
          {"answer", "The Answer"}
        });
      auto page = crow::mustache::load("lesson.html");
      return page.render(ctx);
    });

  // Set the port, use multiple threads, run the app
  app.port(3000).multithreaded().run();

  return 0;
}
