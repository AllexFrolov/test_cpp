cmake_minimum_required(VERSION 3.29)

project(src)

set(SOURCE_LIB Card.cpp Deck.cpp utils.hpp)

add_library(src ${SOURCE_LIB})
# set_target_properties(src PROPERTIES PUBLIC_HEADER Card.hpp 
#     PUBLIC_HEADER Deck.hpp)
# install(TARGETS src LIBRARY DESTINATION lib
#     PUBLIC_HEADER DESTINATION include
#     )