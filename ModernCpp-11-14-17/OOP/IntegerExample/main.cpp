#include <iostream>
#include "Integer.h"

void Print(Integer i);
void Add(int x, int y);

int main() {
    Integer i(5);

    Print(i);

    // copy types
    int *p1 = new int(200);
    // shallow Copy
    int *p2 = p1;
    std::cout << *p2 << std::endl;
    // deep copy
    int *p3 = new int(*p1);
    std::cout << *p3 << std::endl;


    // new lets create a copy of the object created above

    // not recommended it usually have a undefined behavior
    // when copy a class with no copy constructor
    //Integer i2(i);
    // usually copies pointers with shallow copy method
    //Integer i2 = i; // not recomended too

    Integer i2(i);
    Print(i2);

    return 0;
}

void Print(Integer i)
{
    //
    std::cout << "Pointer: " << i.getValue() << std::endl;
}

void Add(int x, int y)
{
    //
}