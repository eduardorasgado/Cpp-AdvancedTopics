#include <iostream>
#include "Integer.h"
#include <utility>

inline void showInteger(Integer i)
{
    std::cout << i.getValue() << std::endl;
}

int main() {
    Integer i1{6};
    showInteger(i1);
    Integer i2{i1};
    showInteger(i2);
    Integer i3{std::move(i2)};
    showInteger(i3);
    Integer i4 = i1+i3;
    showInteger(i4);
    // declared on class using operator+(int)
    Integer i5 = i4+10;
    showInteger(i5);
    //
    Integer i6 = 2+i5;

    return 0;
}