/*
 * COPY AND MOVE SEMANTICS
 *
 * Copy implementation through copy constructor
 * Copy of the object is created
 * Wasteful in case copy is created from a temporary
 *
 * */

#include <iostream>
#include "Integer.h"

// returns a temporary Integer/ r-value
Integer Add(const Integer &a, const Integer &b)
{
    Integer temp;
    temp.setValue(a.getValue() + b.getValue());
    return temp;
}

int main() {
    // Move semantics
    Integer a(1), b(3);

    //std::cout << a.getValue() << std::endl;

    // in this expression: add returns a temporary Integer
    // object, we take the value with its memeber function getValue
    // and then Integer is deleted from memory
    a.setValue(Add(a, b).getValue());

    //std::cout << a.getValue() << std::endl;

    return 0;
}