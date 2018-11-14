/*
 * OPERATOR OVERLOADING
 *
 *  -Custom implementation for primitive operators
 *  -Allows usage of user-defined objects in mathematical expressions
 *  -Overloaded as functions provide a convenient notation
 *  -Implemented as member or global functions
 *  -Require usage of the operator keyword
 *
 *  <ret>operator<#>(<arguments>)
 *
 *  As global functions, require sme no of arguments as the operands
 *  As member functions, one operand is passed as argument through this pointer
 *
 *      - Binary operator will require inly one explicit argument
 *      - Unary operator will not require any explicit argument
 *
 *  Integer operator+(const Integer &, const Integer &)
 *  Integer Integer::operator+(cont Integer &)
 *
 * */

#include <iostream>
#include "Integer.h"

// same implementation of operator + overloading
// already implemented in Integer class can be done here and take
// same effects

// but now params are two objects because the function is not
// owned by no class
Integer operator-(const Integer &a, const Integer &b)
{
    Integer tmp{a.getValue() - b.getValue()};
    return tmp;
}

int main() {
    Integer i1{33};

    Integer i2{22};

    std::cout << i2.getValue() << std::endl;

    // operator overloading is a sintactic sugar
    // behind the scenes at compiler code it is a real function
    auto &&i3 = i2 + i1;

    std::cout << i3.getValue() << std::endl;

    Integer ii{100};

    // operator overloading for substraction implemented as a
    // global function
    // && is a r-value reference
    auto &&i4 = ii-i3;

    std::cout << i4.getValue() << std::endl;

    std::cout << "Counter is: " << Integer::getCount() << std::endl;

    // increment operator overloading
    ++i4;

    // prints: 46
    std::cout << i4.getValue() << std::endl;

    // calling the postincremetal operator
    // prints: 46
    std::cout << i4++.getValue() << std::endl;
    // prints: 47
    std::cout << i4.getValue() << std::endl;

    Integer i5{i4};

    const bool &comp = i4 == i3;
    const bool &comp2 = i4 == i5;

    std::cout << "i4 == i3: " << comp << std::endl;
    std::cout << "i4 == i5: " << comp2 << std::endl;

    std::cout << "---decremental operators----" << std::endl;

    std::cout << i5.getValue() << std::endl;
    // calling pre-decrementl op
    --i5;
    std::cout << i5.getValue() << std::endl;

    // calling post-decremental op
    std::cout << i5--.getValue() << std::endl;
    std::cout << i5.getValue() << std::endl;

    std::cout << "-----end-----" << std::endl;

    return 0;
}