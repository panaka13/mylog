add_library(mylog api.cpp file_logger.cpp stream_logger.cpp timer.cpp)


# specify the C++ standard
set_property(TARGET mylog PROPERTY CXX_STANDARD 17)

