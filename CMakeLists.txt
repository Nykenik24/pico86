cmake_minimum_required(VERSION 3.29)
project(Pico86)

# Sources
file(GLOB_RECURSE SOURCES src/*.c)

# Executable
add_executable(pico86 ${SOURCES})
set_target_properties(pico86 PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Includes
target_include_directories(
	pico86
	PUBLIC ${PROJECT_SOURCE_DIR}/src
)
