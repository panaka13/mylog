cmake_minimum_required(VERSION 3.10)

# set the project name
project(my_log VERSION 1.0)

# output command flags
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_BUILD_TYPE Debug)

# headers folder
include_directories(${CMAKE_SOURCE_DIR}/include)  
include_directories(${CMAKE_SOURCE_DIR}/generated/include)

# configure header file
execute_process(COMMAND date "+%z" OUTPUT_VARIABLE timezone)
math(EXPR timezone_offset "${timezone}/100")
configure_file(configure.h.in ${CMAKE_SOURCE_DIR}/generated/include/configure.h)

add_subdirectory(src)
add_subdirectory(demo)

include(gtest.cmake)
add_subdirectory(test)

