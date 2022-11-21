#!/bin/bash

cargo build --release --target=x86_64-unknown-linux-gnu
mkdir WDHANY

cp ./target/release/wdhany ./WDHANY
cp ./resources/db.sqlite ./WDHANY
cp ./resources/libsqlite.so.0 ./WDHANY
cp ./resources/Rocket.toml ./WDHANY

