cmake_minimum_required(VERSION 3.2)
project(raytracer)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB raytracer_src "src/*.cpp")

include_directories(include)
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -DNDEBUG")
add_executable(raytracer ${raytracer_src})

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})
target_link_libraries(raytracer ${PNG_LIBRARY})
