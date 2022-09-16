cmake_minimum_required(VERSION 3.5)

project(GCCodeCamp-Server)
add_executable(GCCodeCamp-Server main.cpp)

include_directories(/usr/include include)
link_directories(/usr/lib include)

find_package(Crow)
find_package(ZLIB)

add_library(GC-SQL include/sql.cpp)

target_link_libraries(GCCodeCamp-Server PUBLIC Crow::Crow sqlite3 GC-SQL)

file(MAKE_DIRECTORY ${GCCodeCamp-Server_BINARY_DIR}/templates/)
file(MAKE_DIRECTORY ${GCCodeCamp-Server_BINARY_DIR}/static/)

add_custom_command(OUTPUT templates/*
  COMMAND ${CMAKE_COMMAND} -E
  copy ${PROJECT_SOURCE_DIR}/templates/* ${CMAKE_CURRENT_BINARY_DIR}/templates/
  DEPENDS ${PROJECT_SOURCE_DIR}/templates/*
)
add_custom_target(templates_copy ALL DEPENDS templates/*)

add_custom_command(OUTPUT static/*
  COMMAND ${CMAKE_COMMAND} -E
  copy ${PROJECT_SOURCE_DIR}/static/* ${CMAKE_CURRENT_BINARY_DIR}/static/
  DEPENDS ${PROJECT_SOURCE_DIR}/static/*
)
add_custom_target(static_copy ALL DEPENDS static/*)

set(CROW_FEATURES "compression")
