/*
HOMEWORK:

    void Add(int a,int b, int &result) ;    //Add two numbers and return the result through a reference parameter
    void Factorial(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
    void Swap(int &a, int &b) ;            //Swap two numbers through reference arguments
*/
#include <iostream>


void Add(int, int, int&);
void Factorial(int, int&);
void Swap(int&, int&);

int main()
{
    int a{2};
    int b{3};
    int r{};

    // creating references
    int &rRef = r;
    int &aRef = a;
    int &bRef = b;
    
    // 1.
    Add(a, b, rRef);
    std::cout << "Addition: " << a << " + " << b << "= " << rRef << std::endl;

    int c{6};
    Factorial(c, rRef);
    std::cout << "Factorial of " << c << " is: " << rRef << std::endl;

    std::cout << "a: " << a << ", b: " << b << std::endl;
    Swap(aRef, bRef);
    std::cout << "a: " << a << ", b: " << b << std::endl;
    return 0;
}

void Add(int a, int b, int& result)
{
    //
    result = a + b;
}

void Factorial(int a, int &result)
{
    //
    int aux{1};
    result = {1};
    while(aux <= a) { result *=aux; aux++; }
}

void Swap(int &a, int &b)
{
    // swapping without an aux variable
    a = a + b;
    b = a - b;
    a = a - b;
}