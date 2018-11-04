#include <iostream>

void Print(const int *ptr)
{
    std::cout << "Pointer: " << *ptr << std::endl;
    // modifying the value ptr is pointing
    // *ptr = 500;
}

void Print(const int &ref)
{
    std::cout << "Reference: " << ref << std::endl;
}

int main()
{
    // compound types and constant data

    // POINTER TO A INTEGER CONSTANT
    const int CHUNK_SIZE = 512;
    const int *ptr = &CHUNK_SIZE;
    std::cout << *ptr << std::endl;
    // we cannot reassign a read only pointer value
    //ptr = 1024;

    // but we can reassign the reference
    int x{10};
    int y{12};

    ptr = &x;
    std::cout << "Pointer to an integer constant: " << *ptr << std::endl;

    // CONSTANT POINTER TO A INTEGER
    int * const ptr2 = &x;
    // we can change the value inside the memory of the pointer
    *ptr2 = 20;
    std::cout << "Constant pointer to a integer, new value: " << x << std::endl;
    // we cannot change the memory allocation the pointer is refering
    //ptr2 = &y;

    // CONSTANT POINTER TO AN INTEGER CONSTANT
    const int * const ptr3 = &CHUNK_SIZE;

    //
    std::cout << "Constant pointer to an integer(constant): " << *ptr3 << std::endl;

    //
    std::cout << "------------------" << std::endl;

    std::cout << "original x: " << y << std::endl;
    Print(&y);
    std::cout << "original x: " << y << std::endl;


    // CONSTANT REFERENCES
    int nx = 5;
    //const int &ref = x;
    Print(nx);
    return 0;
}