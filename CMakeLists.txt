cmake_minimum_required(VERSION 3.10)

# Set the project name
project(TestProject)

# add -DCMAKE_PREFIX_PATH="path/to/SDL3" to cmake command to use system SDL3
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/SDL")

if (NOT BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS OFF) # If build_shared_libs is not set, set it to static
endif()

# add -USDL3_DIR to cmake command to use system SDL3
set(SDL3_DIR)

add_subdirectory(SDL EXCLUDE_FROM_ALL)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)

# Write to output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

file(GLOB_RECURSE src
    "src/*.cpp"
)

# Add the executable
add_executable(TestProject ${src})

# Link SDL3
target_link_libraries(TestProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)

# Copy assets folder to output directory
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/out)