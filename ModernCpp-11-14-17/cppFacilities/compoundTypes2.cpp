#include <iostream>

int main()
{
    //
    int x = 5;
    const int MAX = 12;
    int &xref = x;
    const int &x2ref = x;

    //pointers
    const int *ptr1 = &x;
    int * const ptr2 = &x;

    // pointers
    const int *ptr3 = &MAX;
    const int *ptr4 = &MAX;

    // references to references
    const int &r1 = xref;
    const int &r2 = x2ref;

    // pointer to reference
    const int *&p_ref1 = ptr1;
    int * const &p_ref2 = ptr2;
    return 0;
}