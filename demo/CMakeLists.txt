include_directories(${CMAKE_SOURCE_DIR})

add_executable(mylog_demo main.cpp)

target_link_libraries(mylog_demo mylog)

# specify the C++ standard
set_property(TARGET mylog_demo PROPERTY CXX_STANDARD 17)
