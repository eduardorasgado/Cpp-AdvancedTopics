#include <iostream>
#include "Car.h"

inline void block()
{
    std::cout << "--------------" << std::endl;
}

int main() {

    // default constructor call
    Car c1;
    c1.Dashboard();

    block();
    // fuel only assignation
    Car c2{10};
    c2.Dashboard();

    block();
    // fuel and passagers
    Car c3{10, 4};
    c3.Dashboard();

    block();

    return 0;
}