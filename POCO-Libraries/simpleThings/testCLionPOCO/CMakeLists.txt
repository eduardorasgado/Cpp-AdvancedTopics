cmake_minimum_required(VERSION 3.10)
project(testCLionPOCO)

add_definitions("-std=c++11")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(testCLionPOCO main.cpp)

target_link_libraries(testCLionPOCO ${CONAN_LIBS})