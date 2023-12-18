cmake_minimum_required(VERSION 3.26)
project(day_23 C)

set(CMAKE_C_STANDARD 23)

add_executable(day_23_part1 part1.c)
add_executable(day_23_part2 part2.c)

# include input.in in the build directory
configure_file(input.in input.in COPYONLY)
