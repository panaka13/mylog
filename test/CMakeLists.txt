include_directories(${CMAKE_BINARY_DIR}/googletest-src/googletest/include/)

add_executable(mylog_test main.cpp simple_log_test.cpp timer_test.cpp 
  type_log_test.cpp util_test.cpp)

target_link_libraries(mylog_test gtest gmock gtest_main mylog)
