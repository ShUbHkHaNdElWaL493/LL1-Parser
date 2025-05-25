add_library(datatypes STATIC datatypes.h datatypes.c)

add_library(first_follow STATIC first_follow.h first_follow.c)
target_link_libraries(first_follow PUBLIC datatypes)

add_library(parse_LL1 STATIC parse_LL1.h parse_LL1.c)
target_link_libraries(parse_LL1 PUBLIC first_follow)