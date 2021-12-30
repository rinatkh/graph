cmake_minimum_required(VERSION 3.20)
project(algorithms)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms main.cpp
        src/IGraph.cpp
        src/ArcGraph.cpp
        src/ListGraph.cpp
        src/MatrixGraph.cpp
        src/SetGraph.cpp)
target_include_directories(algorithms PUBLIC include)
