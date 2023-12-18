cmake_minimum_required(VERSION 3.26)
project(day_20 C)

set(CMAKE_C_STANDARD 23)

add_executable(day_20_part1 part1.c)
add_executable(day_20_part2 part2.c)

# link math library
target_link_libraries(day_20_part1 m)
target_link_libraries(day_20_part2 m)

# include input.in in the build directory
configure_file(input.in input.in COPYONLY)
