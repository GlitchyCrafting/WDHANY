cargo build --release --target=x86_64-pc-windows-msvc
mkdir WDHANY

cp ./target/release/wdhany ./WDHANY
cp ./resources/db.sqlite ./WDHANY
cp ./resources/sqlite.dll ./WDHANY
cp ./resources/Rocket.toml ./WDHANY

