cmake_minimum_required(VERSION 3.22.1)
project(TestProject)

set(CMAKE_CXX_STANDARD 11)

set(LESS_INCLUDE_DIR "/path/to/less/includes")
set(LESS_LIBRARIES "/path/to/less/libraries/libless.so")

set(SYSLOG_INCLUDE_DIR "/path/to/syslog/includes")
set(SYSLOG_LIBRARIES "/path/to/syslog/libraries/libsyslog.so")

add_executable(TestProject main.cpp)

target_include_directories(TestProject PRIVATE ${LESS_INCLUDE_DIR} ${SYSLOG_INCLUDE_DIR})

target_link_libraries(TestProject PRIVATE ${LESS_LIBRARIES} ${SYSLOG_LIBRARIES})