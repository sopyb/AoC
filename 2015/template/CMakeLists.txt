cmake_minimum_required(VERSION 3.26)
project(day_01 C)

set(CMAKE_C_STANDARD 23)

add_executable(day_XX_part1 part1.c)
add_executable(day_XX_part2 part2.c)

# include part1.in and part2.in in the build directory
configure_file(part1.in part1.in COPYONLY)
configure_file(part2.in part2.in COPYONLY)
