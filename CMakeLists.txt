cmake_minimum_required(VERSION 3.11)
project(snake-game)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(creact)
add_executable(app.o src/app.cpp)
target_link_libraries(app.o PUBLIC creact)
