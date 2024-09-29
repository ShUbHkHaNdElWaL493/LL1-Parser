cmake_minimum_required(VERSION 3.10)

project(LL1_Parser)

add_subdirectory(${PROJECT_SOURCE_DIR}/../include ${PROJECT_BINARY_DIR}/include)

# Used to create an executable from a .cpp file
add_executable(LL1_parser LL1_parser.c)

# Used to link new libraries with the project
target_link_libraries(LL1_parser PUBLIC parse_LL1)

# Used to link new directories with the project
target_include_directories(LL1_parser PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/../include"
)