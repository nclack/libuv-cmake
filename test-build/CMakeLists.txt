cmake_minimum_required(VERSION 2.8)
project(test-build)

find_package(uv)
add_executable(hw main.c)
target_add_uv(hw)
