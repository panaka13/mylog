add_library(mylog api.cpp core.cpp logger.cpp)


# specify the C++ standard
set_property(TARGET mylog PROPERTY CXX_STANDARD 17)

