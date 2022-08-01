add_library(
    creact
    SHARED
    src/app.cpp
    src/color.cpp
    src/element.cpp
    src/vector.cpp
)

find_package(Curses REQUIRED)
target_include_directories(creact PUBLIC ${CURSES_INCLUDE_DIR})
target_link_libraries(creact ${CURSES_LIBRARIES})
target_include_directories(creact PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
