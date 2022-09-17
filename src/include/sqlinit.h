#pragma once

#include "sqlite_orm.h"
#include <string>

struct User {
  int id;
  std::string username;
  std::string email;
  std::string password;
  std::string salt;
};

struct Lesson {
  int id;
  std::string name;
  std::string content;
  std::string code;
  std::string answer;
};

auto sqlinit() {
  return sqlite_orm::make_storage("db.sqlite",
                                  sqlite_orm::make_table("USERS",
                                                         sqlite_orm::make_column("ID", &User::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
                                                         sqlite_orm::make_column("USERNAME", &User::username),
                                                         sqlite_orm::make_column("EMAIL", &User::email),
                                                         sqlite_orm::make_column("PASSWORD", &User::password),
                                                         sqlite_orm::make_column("SALT", &User::salt)),
                                  sqlite_orm::make_table("LESSONS",
                                                         sqlite_orm::make_column("ID", &Lesson::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
                                                         sqlite_orm::make_column("NAME", &Lesson::name),
                                                         sqlite_orm::make_column("CONTENT", &Lesson::content),
                                                         sqlite_orm::make_column("CODE", &Lesson::code),
                                                         sqlite_orm::make_column("ANSWER", &Lesson::answer))).sync_schema();
}
