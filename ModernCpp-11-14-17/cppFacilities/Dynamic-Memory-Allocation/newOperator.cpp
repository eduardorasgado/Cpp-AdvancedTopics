/* Memory allocation in C++ */
/*
 * new: allocates memory in the heap
 * delete: deallocates memory
 * Memory that is allocated through new has to be release with delete
 * */

#include <iostream>
#include <cstdlib>

void New()
{
    // allocating a integer in the heap
    //initializing with value of 5
    // new and delete can call constructors and destructors automatically
    // so we can use then to create dynamic objects
    int *p = new int(5);

    std::cout << "p value: " << *p << std::endl;
    // changing the value in the pointer
    *p = 6;
    std::cout << "p value: " << *p << std::endl;
    // deallocating memory from the stack
    delete p;
    // even with delete keyword, pointer p is still pointing to the address
    // so it is recommended to safely take actions
    // it is recommended to assing it a null pointer
    p = nullptr;
    // if we dont care, it will throws exception on failure
}

int main()
{
    //
    New();
    return 0;
}