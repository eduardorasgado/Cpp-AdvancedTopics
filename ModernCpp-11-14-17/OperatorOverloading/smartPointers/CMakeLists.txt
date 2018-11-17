cmake_minimum_required(VERSION 3.12)
project(smartPointers)

set(CMAKE_CXX_STANDARD 14)

add_executable(smartPointers main.cpp Integer.cpp Integer.h IntPtr.cpp IntPtr.h)