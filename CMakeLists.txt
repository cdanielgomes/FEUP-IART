cmake_minimum_required(VERSION 3.13)
project(FEUP_IART)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(FEUP_IART
        src/main.cpp
        src/node.cpp
        src/node.h
        src/search.cpp
        src/search.h
        src/state.cpp
        src/state.h
        src/block.cpp
        src/block.h
        src/DFS.cpp
        src/DFS.h src/astar.cpp src/astar.h)
