cmake_minimum_required(VERSION 3.15)

project(
    TextRecovery
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)
add_subdirectory(data_preparation)
add_subdirectory(main_app)
