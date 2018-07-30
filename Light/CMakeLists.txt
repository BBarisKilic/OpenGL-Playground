cmake_minimum_required(VERSION 3.12)
project(Light)

set(CMAKE_CXX_STANDARD 14)

add_executable(Light main.cpp)

target_link_libraries(${PROJECT_NAME} /usr/lib/x86_64-linux-gnu/libGL.so
        /usr/lib/x86_64-linux-gnu/libGLU.so /usr/lib/x86_64-linux-gnu/libSDL2.so)