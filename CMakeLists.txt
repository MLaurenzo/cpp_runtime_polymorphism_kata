cmake_minimum_required(VERSION 3.8)
project(cpp_runtime_polymorphism_kata)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        main.cpp Wrapper.cpp)

add_executable(cpp_runtime_polymorphism_kata ${SOURCE_FILES})