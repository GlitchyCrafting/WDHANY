#!/bin/bash

mkdir build
cd ./build

cmake ../src
if [[ $? -gt 0 ]]; then
  echo "Fail-ed (Cmake)"
  cd ..
  exit 1
fi
echo "Cmake-d"

make
if [[ $? -gt 0 ]]; then
  echo "Fail-ed (Make)"
  cd ..
  exit 2
fi
echo "Make-d"

./WDHANY
if [[ $? -gt 0 ]]; then
  echo "Fail-ed"
  cd ..
  exit 3
fi
echo "Ran-ed"
cd ..
