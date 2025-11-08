cmake_minimum_required(VERSION 4.0)
project(flux_pl)

set(CMAKE_CXX_STANDARD 20)

add_executable(flux_pl main.cpp
        tokenizer/token/token.hpp
        tokenizer/token/token.cpp)
