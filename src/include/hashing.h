#pragma once

// Argon2
#include <argon2.h>

// STD Libs
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHLEN 64
#define SALTLEN 32

namespace gc {

  class Hasher {

  private:
    uint8_t hash[HASHLEN];
    uint8_t salt[SALTLEN];
    uint32_t tCost = 2;
    uint32_t mCost = (1<<16);
    uint32_t threads = 12;

  public:
    uint8_t hashPwd(const char *pwd) {
      argon2id_hash_raw(tCost, mCost, threads, pwd, strlen((char *)pwd), salt, SALTLEN, hash, HASHLEN);
      return *hash;
    }

    bool checkHash(const char *pwd, uint8_t yourHash) {
      argon2id_hash_raw(tCost, mCost, threads, pwd, strlen((char *)pwd), salt, SALTLEN, hash, HASHLEN);
      if (hash == &yourHash) {
        return true;
      }
      return false;
    }

  };

}
