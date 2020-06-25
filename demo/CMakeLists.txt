add_executable(mylog_demo main.cpp)

target_link_libraries(mylog_demo src)

# specify the C++ standard
set_property(TARGET mylog_demo PROPERTY CXX_STANDARD 17)
