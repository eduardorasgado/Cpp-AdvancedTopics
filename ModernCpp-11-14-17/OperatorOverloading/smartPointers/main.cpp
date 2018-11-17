#include <iostream>
#include "Integer.h"
#include <utility>

inline void showInteger(Integer i)
{
    std::cout << i.getValue() << std::endl;
}

Integer operator+(int x, Integer& obj)
{
    // global operator overloaded
    // int + Integer addition
    Integer temp{x + *obj.m_pInt};
    return temp;
}

void equalsTo(Integer&obj1, Integer &obj2)
{
    if(obj1 == obj2)
    {
        std::cout << "Son iguales" << std::endl;
    }
    else {
        std::cout << "Son distintos" << std::endl;
    }
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
    // global ooperator overloaded
    Integer i6 = 2+i5;
    showInteger(i6);
    showInteger(++i6);
    // no change
    showInteger(i6++);
    // now change can be seen
    showInteger(i6);
    showInteger(--i1);
    showInteger(i1--);
    showInteger(i1);
    equalsTo(i6, i5);
    Integer i3Copy{i3};
    equalsTo(i3, i3Copy);
    std::cout << "-----" << std::endl;
    showInteger(i6);
    i6 =  i4;
    showInteger(i6);
    showInteger(i3);
    // efficient, elegant and fast way to get a copy of an instance
    i3Copy = std::move(i6);
    showInteger(i3Copy);

    return 0;
}