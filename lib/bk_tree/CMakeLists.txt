cmake_minimum_required(VERSION 3.15)

project(
    BKTreeLibrary
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(
    BKTreeLibrary STATIC
)

target_include_directories(BKTreeLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
    BKTreeLibrary PUBLIC
    edit_distance.cpp
    bk_tree_node.cpp
    bk_tree.cpp)
