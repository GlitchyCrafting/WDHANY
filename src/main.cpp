// CROW Libs
#define CROW_MAIN
#include "crow.h"
#include "crow/middlewares/cookie_parser.h"

// Std Libs
#include <stdio.h>
#include <filesystem>

// SQLite_ORM
#include "include/sqlite_orm.h"
#include "include/sqlinit.h"

// User Control
#include "usercontrol.h"

// CryptoPP
#include "include/hashing.h"

int main () {

  // Initialize Everything
  crow::App<crow::CookieParser> app;
  auto database = sqlinit();
  gc::Hasher hasher;

  gc::signup(hasher, "somename", "someemail", "somepassword", database);
  if (gc::login(hasher, "somename", "somepassword", database)) {
    printf("Logged in successfully.");
  }

  // Define the root endpoint
  // TODO make a proper landing page
  CROW_ROUTE(app, "/").methods(crow::HTTPMethod::GET)
    ([](){
      return "There is not a homepage yet.";
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
