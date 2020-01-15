cmake_minimum_required(VERSION 3.15)
project(CSAPP C)

set(CMAKE_C_STANDARD 99)

# Exception Control Flow
add_executable(fork ecf/fork.c)