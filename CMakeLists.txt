cmake_minimum_required(VERSION 2.8)

execute_process(
  COMMAND git describe
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  OUTPUT_VARIABLE GIT_TAG
  OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_definitions("-DGIT_TAG=\"${GIT_TAG}\"")

project(ybhome-server)
add_executable(${PROJECT_NAME} "main.cpp" "mqttserver.cpp" "mqttserver.h" "common.h")
target_link_libraries(ybhome-server -lmosquittopp)

set(CMAKE_BUILD_TYPE Debug)
