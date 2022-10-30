cmake_minimum_required(VERSION 3.5)

project(WDHANY)
add_executable(WDHANY main.cpp)

include_directories(${WDHANY_SOURCE_DIR}/include include)

target_link_libraries(WDHANY PUBLIC sqlite3)

set(CROW_FEATURES "compression")
