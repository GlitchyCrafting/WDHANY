#pragma once

// Hashing Algo
#include <argon2.h>

// STD Libs
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

#define HASHLEN 64
#define SALTLEN 32
#define PWD1 "password"
#define PWD2 "password"

int test(void)
{
    uint8_t hash1[HASHLEN];
    uint8_t hash2[HASHLEN];

    uint8_t salt[SALTLEN];
    memset( salt, 0x00, SALTLEN );

    uint8_t *pwd1 = (uint8_t *)strdup(PWD1);
    uint8_t *pwd2 = (uint8_t *)strdup(PWD2);
    uint32_t pwdlen = strlen((char *)pwd1);

    uint32_t t_cost = 2;            // 2-pass computation
    uint32_t m_cost = (1<<16);      // 64 mebibytes memory usage
    uint32_t parallelism = 1;       // number of threads and lanes

    // high-level API
    argon2id_hash_raw(t_cost, m_cost, parallelism, pwd1, pwdlen, salt, SALTLEN, hash1, HASHLEN);

    argon2id_hash_raw(t_cost, m_cost, parallelism, pwd2, pwdlen, salt, SALTLEN, hash2, HASHLEN);

    for (int i = 0; i < HASHLEN; ++i) {
      if (hash1[i] == hash2[i]) {
        printf("%02x", hash1[i]);
      } else {
        printf("Wrong!");
      }
        printf("\n");
    }

    return 0;
}
