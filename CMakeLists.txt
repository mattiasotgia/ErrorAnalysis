#    ErrorAnalysis - error propagation toolset - C++
#    Author: Mattia Sotgia
#    Version: 0.2 alpha


cmake_minimum_required(VERSION 3.16)

project(ErrorAnalysis VERSION 0.2)

find_package(ROOT)

set(CMAKE_CXX_FLAGS ${ROOT_CXX_FLAGS})

add_compile_options(-I${ROOT_INCLUDE_DIRS})

# inlcude PATHS
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(ErrorAnalysis SHARED src/ErrorAnalysis.cpp)

target_link_libraries(ErrorAnalysis ${ROOT_LIBRARIES})

install(TARGETS ErrorAnalysis DESTINATION /usr/local/lib/)
install(FILES include/ErrorAnalysis.h DESTINATION include)
