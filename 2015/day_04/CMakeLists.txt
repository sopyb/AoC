cmake_minimum_required(VERSION 3.26)
project(day_04 C)

set(CMAKE_C_STANDARD 23)

find_package(OpenSSL REQUIRED)

add_executable(day_04_part1 part1.c)
target_link_libraries(day_04_part1 OpenSSL::Crypto)
add_executable(day_04_part2 part2.c)
target_link_libraries(day_04_part2 OpenSSL::Crypto)

# include input.in in the build directory
configure_file(input.in input.in COPYONLY)
