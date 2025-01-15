cmake_minimum_required(VERSION 3.10)

# Set the project name
project(TestProject)

set(SDL_STATIC ON)
set(SDL_SHARED OFF)

add_subdirectory(SDL EXCLUDE_FROM_ALL)

# Write to output directory
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the executable
add_executable(TestProject test.cpp)

# Link SDL3
target_link_libraries(TestProject PRIVATE SDL3::SDL3)
