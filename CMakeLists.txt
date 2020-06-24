cmake_minimum_required(VERSION 3.10)

# set the project name
project(my_log VERSION 1.0)

# output command flags
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

configure_file(configure.h.in ../generated/include/configure.h)

# headers folder
include_directories(./include)
include_directories(./generated/include)

# main
add_executable(mylog src/main.cpp)

# specify the C++ standard
set_property(TARGET mylog PROPERTY CXX_STANDARD 17)

