cmake_minimum_required(VERSION 3.25)
project(sabr)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp Builder.cpp Project.cpp Spinner.cpp Config.hpp main.cpp)
