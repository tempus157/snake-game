cmake_minimum_required(VERSION 3.11)
project(snake-game)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

file(
    GLOB_RECURSE
    SRC_FILES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_subdirectory(creact)
add_executable(game.out ${SRC_FILES})
target_include_directories(game.out PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(game.out creact)
