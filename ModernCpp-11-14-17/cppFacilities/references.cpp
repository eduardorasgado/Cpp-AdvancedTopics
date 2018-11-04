#include <iostream>

int main()
{
    // Referent
    int x{10};

    // Reference
    // A reference is just an alias for the referent
    // It does not get allocated in the memory as a pointer
    // Reference always need an initializer
    int &xref = x;

    std::cout << "x: " << x << std::endl;
    std::cout << "xref: " << xref << std::endl;
    std::cout << "x address: " << &x << std::endl;
    std::cout << "xref address: " << &xref << std::endl;
    return 0;
}