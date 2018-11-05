#include <stdio.h>
#include <stdlib.h>

int main()
{
    // in cpp we should cast the malloc
    // remember: malloc just allocate the memory, it does not initialize it
    int *p = (int*) malloc(sizeof(int));
    // allocating a value
    *p = 5;
    // we should dereferenciate the value
    printf("value: %d\n", *p);

    // deallocate memory address
    free(p);
    // for safety
    p = NULL;
}