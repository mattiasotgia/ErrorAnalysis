#    ErrorAnalysis - error propagation toolset - C++
#    Author: Mattia Sotgia
#    Version: 0.2 alpha


cmake_minimum_required(VERSION 3.16)

project(ErrorAnalysis VERSION 0.2)

find_package(ROOT)
add_compile_options(ROOT_DEFINITIONS)

# inlcude PATHS
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(ErrorAnalysis SHARED src/ErrorAnalysis.cpp)

install(TARGETS ErrorAnalysis DESTINATION /usr/lib)
install(FILES include/ErrorAnalysis.h DESTINATION include)
