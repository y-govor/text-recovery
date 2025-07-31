cmake_minimum_required(VERSION 3.15)

project(
    TrieLibrary
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(
    TrieLibrary STATIC
)

target_include_directories(TrieLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(
    TrieLibrary PUBLIC
    trie_node.cpp
    trie.cpp)
