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
void Swap(int *, int*);
void Factorial(int*, int*);

int main()
{
    int a{-2};
    int b{6};
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

    //
    std::cout << "a: " << *pa << ", b: " << *pb << std::endl;
    Swap(pa, pb);
    std::cout << "a: " << *pa << ", b: " << *pb << std::endl;

    Factorial(pa, pr);
    std::cout << "The factorial of " << *pa << " is: " << *pr << std::endl;
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

void Swap(int *a, int*b)
{
    // swapping values of two integers
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void Factorial(int *a, int *result)
{
    //get the factorial of a num and assign it to result
    int aux{1};
    *result = 1;
    while (aux <= *a) { *result *= aux; aux++; }
}