cmake_minimum_required(VERSION 2.8)

project(ybhome-server)
add_executable(${PROJECT_NAME} "main.cpp" "mqttserver.cpp" "mqttserver.h" "common.h")
target_link_libraries(ybhome-server -lmosquittopp)

set(CMAKE_BUILD_TYPE Debug)
