#include <iostream>
#include "Car.h"
#include "Aircraft.h"

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

    // Aircrafts ----------------
    Aircraft a1;
    a1.profile();

    block();
    Aircraft a2{20400.300, "Mazzimo Ferrutti"};
    a2.profile();

    block();
    Aircraft a3{60680.455, "Karim Nafatni", 40, 211, 4002445};
    a3.profile();

    block();
    auto a4 = new Aircraft(40300.202, "Troy Booker", 120, 431, 20030401, 8);
    a4->profile();

    block();
    delete a4;

    return 0;
}