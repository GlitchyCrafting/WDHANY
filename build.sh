#!/bin/bash

cmake .
if [[ $? -gt 0 ]]; then
  echo "Fail-ed (Cmake)"
  exit 1
fi
echo "Cmake-d"
sleep 5

make
if [[ $? -gt 0 ]]; then
  echo "Fail-ed (Make)"
  exit 2
fi
echo "Make-d"
sleep 5

cd ./build
./WDHANY
if [[ $? -gt 0 ]]; then
  echo "Fail-ed"
  exit 3
fi
echo "Ran-ed"
cd ..
