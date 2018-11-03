//
// Created by cheetos on 2/11/18.
//

#include <iostream>

int main()
{
    // SCALAR TYPE UNIFORM INITIALIZATION
    // uniform initalization gives a default value to
    // a not initialized variable
    int i{0};
    //int i; // printing a variable without initialization usually gives you
    // a garbage value or error
    std::cout << i << std::endl;

    //char ch; // Printing value of a non initialized char type variable
    // can cause character bugs
    char ch{}; // default value even when there is not a value given
    std::cout << ch << std::endl;
    ch ='a';
    std::cout << ch << std::endl;

    float f{123.54f};

    bool floag{true};
    unsigned int x{ 5643 };

    return 0;
}