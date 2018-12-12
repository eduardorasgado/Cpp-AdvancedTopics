# Poco and Boost application

Compile it using conan package manager.

Instructions:

https://docs.conan.io/en/latest/getting_started.html

conan must be installed and poco libraries in conan cache or lib\
conanfile created
CMakeLists.txt created

mkdir build && cd build
conan install ..

and:(inside build folder in main_project/build)\
(linux, mac)\
$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
