#!/bin/bash

cmake .
make
cd ./build
./WDHANY
cd ..
