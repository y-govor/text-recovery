cmake_minimum_required(VERSION 3.15)

project(
    WordProbLibrary
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(
    WordProbLibrary STATIC
)

target_include_directories(WordProbLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
    WordProbLibrary PUBLIC
    word_prob.cpp)
