#!/bin/bash

cd ./build

cmake -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_C_COMPILER=/usr/bin/clang ../src
if [[ $? -gt 0 ]]; then
  echo "Fail-ed (Cmake)"
  cd ..
  exit 1
fi
echo "Cmake-d"

make -j$(nproc)
if [[ $? -gt 0 ]]; then
  echo "Fail-ed (Make)"
  cd ..
  exit 2
fi
echo "Make-d"
