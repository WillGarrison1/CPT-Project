cmake_minimum_required(VERSION 3.10)

# Set the project name
project(TestProject)

# add -DCMAKE_PREFIX_PATH="path/to/SDL3" to cmake command to use system SDL3
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/SDL")

if (NOT BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS OFF) # If build_shared_libs is not set, set it to static
endif()

add_subdirectory(SDL EXCLUDE_FROM_ALL)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)

# Write to output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

file(GLOB_RECURSE src
    "src/*.cpp"
)

# Add the executable
add_executable(TestProject ${src})

# Add optimizations and warnings for GCC and Clang if in RELEASE mode

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(TestProject PRIVATE -O3 -Wall -Wextra -Wpedantic)
    endif()
elseif (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_compile_options(TestProject PRIVATE -O0 -g -Wall -Wextra -Wpedantic)
    endif()
endif()

# Link SDL3
target_link_libraries(TestProject PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)

# Copy assets folder to output directory
set(ASSETS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/assets)
set(COPY_DIR ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/assets)
file(GLOB TEXTURES 
    ${ASSETS_DIR}/*.png 
    ${ASSETS_DIR}/*.jpg 
    ${ASSETS_DIR}/*.jpeg 
    ${ASSETS_DIR}/*.bmp)


add_custom_command(
    OUTPUT ${COPY_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_DIR} ${COPY_DIR}
    COMMENT "Copying textures to output directory"
)

add_custom_command(
    TARGET TestProject POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSETS_DIR} ${COPY_DIR}
    COMMENT "Copying textures to output directory"
)
