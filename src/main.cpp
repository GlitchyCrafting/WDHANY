// CROW Libs
#define CROW_MAIN
#include "crow.h"
#include "crow/middlewares/cookie_parser.h"

// Std Libs
#include <stdio.h>
#include <filesystem>

// GC Libs
#include "include/sql.h"

int main () {
  // Initialize Everything
  crow::App<crow::CookieParser> app;
  gc::SQL database;

  // Setup for first start.
  if (!std::filesystem::exists("./db.sqlite")) {
    printf("First time?\n");
    database.init("db.sqlite");
    database.exec(
                  "CREATE TABLE USERS(            " \
                  "ID INT PRIMARY KEY   NOT NULL, " \
                  "USERNAME       TEXT  NOT NULL, " \
                  "PASSWORD       TEXT  NOT NULL, " \
                  "SALT           TEXT  NOT NULL);"
                  );
    database.exec(
                  "CREATE TABLE LESSONS(          " \
                  "ID INT PRIMARY KEY   NOT NULL, " \
                  "TITLE          TEXT  NOT NULL, " \
                  "CONTENT        TEXT  NOT NULL, " \
                  "CODE           TEXT  NOT NULL, " \
                  "CODE_ANSWER    TEXT  NOT NULL);"
                  );
  } else {
    database.init("db.sqlite");
  }

  // Define the root endpoint
  // TODO make a proper landing page
  CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)
    ([](crow::response &res){
      res.redirect("/lesson/0");
      res.end();
    });

  // Define the lesson endpoint
  // TODO IN-PROGRESS make a lessons page that grabs a lesson from the db
  CROW_ROUTE(app, "/lesson/<int>").methods(crow::HTTPMethod::POST, crow::HTTPMethod::GET)
    ([](const crow::request& req, int id) {
      std::cout << req.body;
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

  CROW_ROUTE(app, "/signup").methods(crow::HTTPMethod::POST, crow::HTTPMethod::GET)
    ([]() {
      auto page = crow::mustache::load("signup.html");
      return page.render();
    });

  CROW_ROUTE(app, "/login").methods(crow::HTTPMethod::POST, crow::HTTPMethod::GET)
    ([]() {
      auto page = crow::mustache::load("login.html");
      return page.render();
    });

  // Set the port, use multiple threads, run the app
  app.port(3000).multithreaded().run();

  return 0;
}
