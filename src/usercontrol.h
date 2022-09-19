#pragma once

#include "include/sqlite_orm.h"
#include "include/hashing.h"
#include "include/sqlite_orm.h"
#include "include/sqlinit.h"
#include <string>
#include <iostream>

namespace gc {

  template<typename T>
  bool login(gc::Hasher hasher, std::string username, std::string password, T database) {
     auto pwd = database.select(&User::password, sqlite_orm::where(sqlite_orm::eq(&User::username, username)));
     if (hasher.hashPwd(pwd[0].c_str()) == hasher.hashPwd(password.c_str())) {
       return true;
     }
     return false;
  }

  template <typename T>
  void signup(gc::Hasher hasher, std::string username, std::string email, std::string password, T database) {
    uint8_t pwd = hasher.hashPwd(password.c_str());
    database.insert(User{-1, username, email, password});
  }

} // namespace gc
