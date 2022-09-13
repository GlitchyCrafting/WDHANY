#include "sql.h"

namespace gc {

  const char *database;
  sqlite3 *db;
  char *errMsg;

  SQL::SQL() {
    printf("Don't forget to attach a database, you don't want the Memory Address Gods to get mad do you?\n");
  }

  SQL::~SQL() {
    sqlite3_close(db);
    sqlite3_free(errMsg);
    printf("I am the reason for that SIGSEGV, I just didn't feel like having checks for an open database.");
  }

  void SQL::init(const char *base) {
    database = base;
    if (sqlite3_open(database, &db) != SQLITE_OK) {
      printf("DB Connect: %s\n", sqlite3_errmsg(db));
    }
    printf("Good thing I reminded you. You would have gotten a SIGSEGV otherwise.\n");
  }

  void SQL::exec(const char *statement) {
    if (sqlite3_exec(db, statement, callback, 0, &errMsg) != SQLITE_OK) {
      printf("Could not execute statement: %s\nError: %s\n", statement, errMsg);
      sqlite3_free(errMsg);
    }
  }

  int SQL::callback(void *NotUsed, int argc, char **argv, char **azColName) {
      int i;
      for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
      }
      printf("\n");
      return 0;
    }

} // namespace gc
