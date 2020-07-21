add_library(
  mylog api.cpp file_logger.cpp stream_logger.cpp formatter.cpp timer.cpp 
  util.cpp daily_logger.cpp)

# specify the C++ standard
set_property(TARGET mylog PROPERTY CXX_STANDARD 17)

