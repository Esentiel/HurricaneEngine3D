cmake_minimum_required(VERSION 3.16)

project(HurricaneEngine3D)

if (WIN32)
    set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
    set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
endif()

#add_subdirectory (physics)
add_subdirectory (renderer)
add_subdirectory (launcher)
