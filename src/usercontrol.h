#pragma once

#include "include/sqlite_orm.h"
#include "include/hashing.h"
#include "include/sqlite_orm.h"
#include "include/sqlinit.h"
#include <string>
#include <iostream>

namespace gc {

  template<typename T>
  bool login(gc::Hasher hasher, const char *username, const char *password, T database) {
     auto pwd = database.select(&User::password, sqlite_orm::where(sqlite_orm::eq(&User::username, username)));
     // std::cout << pwd << "\n";
     // if (hasher.hashPwd(std::get<0>(pwd[0])) == hasher.hashPwd(password)) {
       // return true;
     // }
     return false;
  }

  template <typename T>
  void signup(gc::Hasher hasher, const char *username, const char *email, const char *password, T database) {
    uint8_t pwd = hasher.hashPwd(password);
    database.insert(User{-1, username, email, password});
  }

} // namespace gc
