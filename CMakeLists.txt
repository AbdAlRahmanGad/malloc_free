cmake_minimum_required(VERSION 3.28)
project(malloc C)

set(CMAKE_C_STANDARD 99)

add_executable(malloc main.c
        mem.c)
