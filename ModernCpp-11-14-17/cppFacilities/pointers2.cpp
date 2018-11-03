/*
 * HOMEWORK:
 *
 *  int Add(int *a, int *b) ;    //Add two numbers and return the sum
    void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
    void Swap(int *a, int *b) ;  //Swap the value of two integers
    void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argument
 *
 * */
#include <iostream>

int Add(int*, int*);
void AddVal(int*, int*, int*);

int main()
{
    int a{5};
    int b{10};
    int result{};

    //pointers
    int *pa{&a};
    int *pb{&b};
    int *pr{&result};

    // returning the result
    int directResult{Add(pa, pb)};
    std::cout << "First result: " << directResult << std::endl;

    //
    AddVal(pa, pb, pr);
    std::cout << "Second result: " << result << std::endl;

    return 0;
}

int Add(int *a, int *b)
{
    std::cout << " Addition " << std::endl;
    int sum = *a + *b;
    return sum;
}

void AddVal(int *a, int *b, int*result)
{
    // this function do not return a value
    // set a new value to result instead
    std::cout << " Addition 2 " << std::endl;
    *result = *a + *b;
}