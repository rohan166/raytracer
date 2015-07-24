cmake_minimum_required(VERSION 3.2)
project(raytracer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Camera.cpp
    Camera.h
    main.cpp
    Point3.cpp
    Point3.h
    Ray.cpp
    Ray.h
    Sampler.cpp
    Sampler.h
    Scene.h
    Vector3.cpp
    Vector3.h)

add_executable(raytracer ${SOURCE_FILES} Rectangle.cpp Rectangle.h Triangle.cpp Triangle.h Primitive.cpp Primitive.h)