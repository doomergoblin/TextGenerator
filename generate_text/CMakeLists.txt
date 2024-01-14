cmake_minimum_required(VERSION 3.24)
project(generate_text)

set(CMAKE_CXX_STANDARD 20)

add_executable(generate_text main.cpp text_generator.cc)
