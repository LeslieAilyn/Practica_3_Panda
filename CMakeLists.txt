cmake_minimum_required(VERSION 4.3)
project(Panda C)

set(CMAKE_C_STANDARD 23)

add_executable(Panda main.c  zoologico.c zoologico.h)
