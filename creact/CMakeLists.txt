add_library(
    creact.out
    main.cpp
    public/App.cpp
    public/LifeCycle.cpp
    public/Object.cpp
    public/Scene.cpp
    public/Vector.cpp
    private/AppData.cpp
    private/AsyncHandler.cpp
    private/ColorUtility.cpp
    private/Input.cpp
)

find_package(Curses REQUIRED)
target_include_directories(creact.out PUBLIC ${CURSES_INCLUDE_DIR})
target_link_libraries(creact.out ${CURSES_LIBRARIES})
