cmake_minimum_required(VERSION 3.14)
project(work_draw_all)

set(CMAKE_CXX_STANDARD 14)

include_directories(~/root/install_root/include)


add_executable(plotter.cpp
        FormatOfEverything.h
        plotter.cpp particles_data.h Particles.cpp FormatPad.cpp)


