#include <stdio.h>
#include <stdlib.h>

int main()
{
    // in cpp we should cast the malloc
    // remember: malloc just allocate the memory, it does not initialize it
    int *p = (int*) malloc(sizeof(int));
    // for safety we should check the value in the pointer
    if(p == NULL)
    {
        // memory allocation could fails, we need to handles this
        printf("Failed to allocate memory\n");
        return -1;
    }
    // allocating a value
    *p = 5;
    // we should dereferenciate the value
    printf("malloc value: %d\n", *p);

    // deallocate memory address
    free(p);
    // for safety
    p = NULL;

    // calloc: allocate the memory and initializes the memory to zero
    // arg1: number of elements we want to allocate, arg2: size of the element
    int *pc = (int*) calloc(1,sizeof(int));

    if(pc == NULL)
    {
        printf("Failed to allocate memory\n");
        return -1;
    }

    *pc = 14;

    printf("calloc value: %d\n", *pc);

    free(pc);
    pc = NULL;
    free(pc);

    // Allocating arrays
    int *pArr = (int*) malloc(5 * sizeof(int));
    if(pArr == NULL)
    {
        printf("Failed to allocate memory");
        return -1;
    }
    // introducing values in the C like array pointer
    // for more info:
    // https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
    for (int i = 0; i < 5; ++i)
    {
        *(pArr+i) = i;
    }

    // showing the values within the array
    for (int j = 0; j < 5; ++j) {
        printf("%d ", *(pArr+j));
        if(j == 4) printf("\n");
    }

    // deallocating memory from pointer
    free(pArr);
    pArr = NULL;
    free(pArr);

    // IMPORTANT:
    // If we do not free allocation we can cause a memory leak

    return 0;
}