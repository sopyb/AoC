# ! This needs the janosson library
# ! Debian/Ubuntu: sudo apt-get install libjansson-dev
# ! Fedora:        sudo dnf install jansson-devel
# ! Arch Linux:    sudo pacman -S jansson
# ! macOS:         brew install jansson

cmake_minimum_required(VERSION 3.26)
project(day_12 C)

set(CMAKE_C_STANDARD 23)

## find jansson
find_library(JANSSON_LIBRARY NAMES jansson)
find_path(JANSSON_INCLUDE_DIR NAMES jansson.h)

add_executable(day_12_part1 part1.c)
add_executable(day_12_part2 part2.c)

# link jansson
include_directories(${JANSSON_INCLUDE_DIR})
target_link_libraries(day_12_part1 ${JANSSON_LIBRARY})
target_link_libraries(day_12_part2 ${JANSSON_LIBRARY})

# include input.in in the build directory
configure_file(input.in input.in COPYONLY)
