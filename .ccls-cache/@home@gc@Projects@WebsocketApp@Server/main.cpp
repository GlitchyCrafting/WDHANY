// CROW Libs
#define CROW_MAIN
#include <crow.h>
#include <crow/middlewares/cookie_parser.h>

// Std Libs
#include <stdio.h>
#include <filesystem>

// GC Libs
#include "sql.h"

int main () {
  // Initialize Everything
  crow::App<crow::CookieParser> app;
  gc::SQL database;

  // Setup for first start. Ignore the "no member named 'filesystem' in namespace 'std'" error, it should compile just fine.
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
  CROW_ROUTE(app, "/")([](crow::response &res){
    res.redirect("/lesson");
    res.end();
  });

  // Define the lesson endpoint
  // TODO IN-PROGRESS make a lessons page that grabs a lesson from the db
  CROW_ROUTE(app, "/lesson")([](){
    auto page = crow::mustache::load("lesson.html").render();
    return page;
  });

  // Set the port, use multiple threads, run the app
  app.port(3000).multithreaded().run();

  return 0;
}
