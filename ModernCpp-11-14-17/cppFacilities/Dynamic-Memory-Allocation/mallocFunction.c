/*
 * MEMORY MANAGEMENT in C/C++
 *
 * STACK- Allocated automatically for local variables
 * DATA SECTION - Allocated for global and static data
 * HEAP - Allocated at runtime
 *
 * All the memory is taken from the process address space
 *
 * C/C++ programs provide support for memory allocation at runtime
 * (also called dynamic memory)
 *
 * Allocations on the heap have to be managed by the programmer
 *
 * Atack and data section allocaion are managed by c/c++ at run time
 * */

/*
 * DYNAMIC MEMORY ALLOCATION IN C
 *
 * C provides various functions for allocating memmory from the heap
 *
 *  malloc: allocate raw memory on the heap
 *  calloc: allocates memory on the heap and initializers it to zero
 *  realloc: alloctes larger chunk of memory for an existing allocation
 *  free: deallicates/ releases the momory allocated through the above functions
 * */

// for C handles
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // we should specifies the size of memory should be allocated
    // malloc just allocate memory, it does not initialize it
    int *p = malloc(sizeof(int));

    // if we try to run this code and compile it in a .cpp extension we should
    // add a cast to malloc
    //int *p = (int*)malloc(sizeof(in));

    // allocate a value inside the memory space created
    *p = 5;
    // showing the value within the pointer
    printf("value: %d\n", *p);

    // deallocating memory
    free(p);
    // it is recomended to reassing null to the pointer in case we
    // free again the pointer as error
    p = NULL;
    // assining Null to pointer will avoid errors when try to deallocate memory
    free(p);
    free(p);

    return 0;
}