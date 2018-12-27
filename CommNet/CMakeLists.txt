cmake_minimum_required(VERSION 3.13)
project(CommNet)

include_directories(include)
include_directories(class)
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES ${DIR_SRCS} src/main.cpp include/commNet.h class/node.cpp class/node.h src/netOperate.cpp src/dijkstra.cpp src/aveLen.cpp)



add_executable(CommNet ${SOURCE_FILES})

