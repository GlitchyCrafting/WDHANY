#pragma once

#include "sqlite_orm.h"

struct User {
  int id;
  const char *username;
  const char *email;
  const char *password;
};

struct Lesson {
  int id;
  const char *name;
  const char *content;
  const char *code;
  const char *answer;
};

auto sqlinit() {
  auto database = sqlite_orm::make_storage("db.sqlite",
                                  sqlite_orm::make_table("USERS",
                                                         sqlite_orm::make_column("ID", &User::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
                                                         sqlite_orm::make_column("USERNAME", &User::username),
                                                         sqlite_orm::make_column("EMAIL", &User::email),
                                                         sqlite_orm::make_column("PASSWORD", &User::password)),
                                  sqlite_orm::make_table("LESSONS",
                                                         sqlite_orm::make_column("ID", &Lesson::id, sqlite_orm::autoincrement(), sqlite_orm::primary_key()),
                                                         sqlite_orm::make_column("NAME", &Lesson::name),
                                                         sqlite_orm::make_column("CONTENT", &Lesson::content),
                                                         sqlite_orm::make_column("CODE", &Lesson::code),
                                                         sqlite_orm::make_column("ANSWER", &Lesson::answer)));
  database.sync_schema();
  return database;
}

void playground() {
  auto database = sqlinit();
  database;
}
