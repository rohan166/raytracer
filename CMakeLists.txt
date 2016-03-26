cmake_minimum_required(VERSION 3.2)
project(raytracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(GLOB raytracer_src "src/*.cpp")

include_directories(include)
add_executable(raytracer ${raytracer_src})