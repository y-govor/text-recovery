cmake_minimum_required(VERSION 3.15)

project(
    ArgParserLibrary
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(
    ArgParserLibrary STATIC
)

target_include_directories(ArgParserLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
    ArgParserLibrary PUBLIC
    argument.cpp
    arg_parser.cpp)
