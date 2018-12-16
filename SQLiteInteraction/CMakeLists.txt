cmake_minimum_required(VERSION 3.13)
project(SQLiteInteraction)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(SQLiteInteraction main.cpp)
target_link_libraries(SQLiteInteraction ${CONAN_LIBS})