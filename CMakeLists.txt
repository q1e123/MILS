cmake_minimum_required(VERSION 3.14)
project(MILS C)

set(CMAKE_C_STANDARD 11)

add_executable(MILS src/main.c src/utils.c include/utils.h src/errors.c include/errors.h src/builtin.c include/builtin.h)