#   Shubh Khandelwal

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(datatypes STATIC datatypes/datatypes.hpp datatypes/datatypes.cpp)

add_library(parse STATIC parse/parse.hpp parse/parse.cpp)
target_link_libraries(parse PUBLIC datatypes)