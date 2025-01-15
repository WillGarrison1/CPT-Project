cmake_minimum_required(VERSION 3.10)

# Set the project name
project(TestProject)

if (CPT_SHARED)
    set(SDL_STATIC OFF)
    set(SDL_SHARED ON)
else()
    set(SDL_STATIC ON)
    set(SDL_SHARED OFF)
endif()

add_subdirectory(SDL EXCLUDE_FROM_ALL)

# Write to output directory
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB_RECURSE src
    "src/*.cpp"
)

# Add the executable
add_executable(TestProject ${src})

# Link SDL3
target_link_libraries(TestProject PRIVATE SDL3::SDL3)