cmake_minimum_required(VERSION 3.12)
project(e3)

set(CMAKE_CXX_STANDARD 14)

add_executable(e3 e3.cpp point.h polygone.h polygone.cpp segment.cpp segment.h)