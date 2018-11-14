#include <iostream>
#include "Integer.h"

int main() {
    Integer i1{45};
    Integer i2{10};

    std::cout << i1.getValue() << std::endl;

    // calling sum operator
    Integer i3{i1 + i2};

    std::cout << i3.getValue() << std::endl;
    std::cout << i1.getValue() << std::endl;
    std::cout << i2.getValue() << std::endl;
    return 0;
}