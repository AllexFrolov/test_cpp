cmake_minimum_required(VERSION 3.29)

project(src)

set(SOURCE_LIB Card.cpp Deck.cpp utils.hpp)

add_library(src ${SOURCE_LIB})