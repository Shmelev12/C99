cmake_minimum_required(VERSION 3.13)
project(longm C)

set(CMAKE_C_STANDARD 99)

add_executable(BUILD000 src/longmath.c headers/longmath.h tests/testlongmath.c)