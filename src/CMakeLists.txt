cmake_minimum_required(VERSION 3.6)
project(Random_Walk_with_Restart)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.h Graph.cpp dist_csv_formatter.h dist_csv_formatter.cpp RandomWalker.h RandomWalker.cpp RandomWalkerGenerator.h RandomWalkGenerator.cpp)
add_executable(Random_Walk_with_Restart ${SOURCE_FILES})