#include <iostream>
#include "Integer.h"

int main() {
    Integer i1{45};
    Integer i2{10};

    // calling sum operator
    Integer i3{i1 + i2};

    std::cout << i3.getValue() << std::endl;

    //pre incremental operator
    std::cout << (++i3).getValue() << std::endl;
    // post incremental operator
    std::cout << (i3++).getValue() << std::endl;
    std::cout << i3.getValue() << std::endl;

    return 0;
}