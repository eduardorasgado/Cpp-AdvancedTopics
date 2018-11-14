#include <iostream>
#include "Integer.h"

inline void showData(Integer& i)
{
    std::cout << i.getValue() << std::endl;
}

inline void showData2(Integer i)
{
    std::cout << i.getValue() << std::endl;
}

int main() {
    Integer i1{45};
    Integer i2{10};

    // calling sum operator
    Integer i3{i1 + i2};

    showData(i3);

    //pre incremental operator
    showData(++i3);
    // post incremental operator
    showData2(i3++);
    showData(i3);

    Integer i4{i3};

    if(i3 == i4) std::cout << "i3 is equal to i4" << std::endl;
    if(!(i3 ==i2)) std::cout << "i3 is different than i2" << std::endl;

    // calling the assignation operation already overloaded
    i1 =  i4;
    showData(i1);

    return 0;
}