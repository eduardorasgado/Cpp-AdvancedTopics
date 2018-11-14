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

    Integer i4{i3};

    if(i3 == i4) std::cout << "i3 is equal to i4" << std::endl;
    if(!(i3 ==i2)) std::cout << "i3 is different than i2" << std::endl;

    return 0;
}