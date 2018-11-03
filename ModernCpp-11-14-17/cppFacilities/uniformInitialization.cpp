//
// Created by cheetos on 2/11/18.
//

#include <iostream>
// a safe method to initialize a list
#include <initializer_list>
#include <algorithm>
#include <iterator>

// macro
#define space() (std::cout << std::endl)

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

    // float uniform initialization
    float myfloat{123.54f};
    //      type reassignation
    float f = 1.2f;
    // lets pass the value
    // does not allow conversions from one type to another type
    //int val1 { f }; // warning: narrowing conversion of ‘f’ from ‘float’ to ‘int’
    int val1 = f; // data loss, not recomended
    std::cout << f << std::endl;
    std::cout << val1 << std::endl;

    bool floag{true};
    unsigned int x{ 5643 };

    // initializer list use
    std::initializer_list<int> myVector{1,2,3,4,5,6,7,8};

    // showing list by using new foreach loop
    for (auto v : myVector) std::cout << v << " ";
    space();

    // showing list by using STL
    std::ostream_iterator<int> output(std::cout, " ");
    std::copy(myVector.begin(), myVector.end(), output);
    space();

    return 0;
}