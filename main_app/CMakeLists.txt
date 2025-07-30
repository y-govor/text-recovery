cmake_minimum_required(VERSION 3.15)

project(
    MainApp
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(recover_text
    main.cpp)
