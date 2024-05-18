cmake_minimum_required(VERSION 3.20)

project(Algorithms CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING
        "Default build type: Debug" FORCE)
endif()

add_compile_options(-Wall -Werror -Wpedantic -Wconversion)

add_subdirectory(utils)
add_subdirectory(longest_common_substring)