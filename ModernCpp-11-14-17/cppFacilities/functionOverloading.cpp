#include <iostream>
#define Print(A) (std::cout << A << std::endl)

int Add(int a, int b)
{
    return a + b;
}

// function overloading
double Add(double a, double b)
{
    return a + b;
}

// overloading does not let  us to create excatly a clone of function
//void showing(int x);
//void showing(int x);

void show(int *x)
{
    std::cout << "Actual value: " << *x << std::endl;
    *x = 5;
    std::cout << "Actual value: " << *x << std::endl;
}

/* 
 extern "C"

 extern C let the code talk to not manage mangling
 which blocks any posibility to talk other languages or C
 with extern "C", the c++ compiler avoids ***name mangling***
 and gives us a chance to talk to other languages.

 -COmpiler diretive applied on global functions and variables
 -Supresses name mangling of the type on which it is applied
 -Can be applied only to one function in a set of overloaded functions
 -Allows C++ finctions to be called from C or other languages
 -Just declared on declarations not on definitions
*/
extern "C" void show(const int *x)
{
    std::cout << "Actual value(const): " << *x << std::endl;
}

int main()
{
    // FUNCTION OVERLOADING
    /*
    -Two or more functions declared with the same name
        Arguments should differ in type and/or number
        For pointers and references arguments, qialifiers participate in overload
        return type is ignored
        For member functions, qualifiers participate in overload
    - Different implementations of the same behaviour
    - The correct implementation is chosen based on the arguments
    -This is resolved at compile time: static polimorphism
    -Convenience for the caller

    How do the compiler manages the functions in FO?
        Name Mangling: varies from compiler to compiler
    */
    auto result{Add(3,5)};
    Print(result);

    // adding doubles
    auto result2{Add(3.1, 6.2)};
    Print(result2);

    int value = 4;
    show(&value);
    
    const int value2 = 44;
    show(&value2);
    return 0;
}