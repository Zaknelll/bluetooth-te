cmake_minimum_required(VERSION 3.13)

project(untitled2_lol)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_BUILD_TYPE Debug)

#link_libraries(ws2_32 wsock32)
link_libraries(setupapi setupapi)

#add_executable(untitled2 main.cpp)
#add_executable(untitled2_lol main.cpp lol.cpp)
add_executable(untitled2_lol usbFinder.cpp)
