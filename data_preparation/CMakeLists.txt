cmake_minimum_required(VERSION 3.15)

project(
    DataPreparation
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(prepare_data
    arg_parser_ex.cpp
    main.cpp)

target_link_libraries(prepare_data ArgParserLibrary)
