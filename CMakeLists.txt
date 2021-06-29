cmake_minimum_required(VERSION 3.14)
project(work_draw_all)

set(CMAKE_CXX_STANDARD 14)

include_directories(~/Programs/root_62400/root/include)


add_executable(plotter.cpp
        FormatOfEverything.h
        plotter.cpp particles_data.h Particles.cpp)


