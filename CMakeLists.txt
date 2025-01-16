cmake_minimum_required(VERSION 3.30)
project(cliqs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_EXTENSIONS FALSE)

add_subdirectory(library)
if (CLIQS_BUILD_SAMPLE)
    add_subdirectory(sample)
endif()