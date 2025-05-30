cmake_minimum_required(VERSION 3.10)
project(UpperCup)

set(CMAKE_CXX_STANDARD 11)

include_directories(
    ${CMAKE_SOURCE_DIR}/raylib-win/include
    ${CMAKE_SOURCE_DIR}/game/include
)

link_directories(${CMAKE_SOURCE_DIR}/raylib-win/lib)

# Tambahkan source
add_executable(game 
    main.cpp
    game/src/home_screen.cpp
    game/src/playing.cpp
    game/src/game_manager.cpp
    game/src/game_loop.cpp
    game/src/obstacle.cpp
    game/src/renderable.cpp
    game/src/cup.cpp
)

if(WIN32)
    # Windows target
    target_link_libraries(game raylib opengl32 gdi32 winmm)
elseif(UNIX)
    # Linux target
    find_package(raylib REQUIRED)
    target_link_libraries(game raylib m pthread dl X11)
endif()
