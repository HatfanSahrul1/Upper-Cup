cmake_minimum_required(VERSION 3.10)
project(UpperCup)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/raylib-win/include)
link_directories(${CMAKE_SOURCE_DIR}/raylib-win/lib)

# Tambahkan source
add_executable(game main.cpp)

if(WIN32)
    # Windows target
    target_link_libraries(game raylib opengl32 gdi32 winmm)
elseif(UNIX)
    # Linux target
    find_package(raylib REQUIRED)
    target_link_libraries(game raylib m pthread dl X11)
endif()
