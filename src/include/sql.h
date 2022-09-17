#pragma once

#include <sqlite3.h>
#include <stdio.h>
#include <vector>

namespace gc {
  class SQL{
    public:
      SQL();
      ~SQL();
      void init(const char *base);
      void exec(const char *statement);

  private:
      const char *database;
      sqlite3 *db;
      char *errMsg;
      static int callback(void *NotUsed, int argc, char **argv, char **azColName);
  };
} // namespace gc
