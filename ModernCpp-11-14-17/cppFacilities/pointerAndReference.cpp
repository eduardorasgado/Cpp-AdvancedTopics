#include <iostream>

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void Print(int*  ptr)
{
    std::cout << "Passing as pointer: " << std::endl;
    // excepting a pointer
    if(ptr != nullptr) std::cout << *ptr << std::endl;
    else std::cout << "It is a null pointer." << std::endl;
}

void Print(int& ptr)
{
    std::cout << "Passing as reference: " << std::endl;
    std::cout << ptr << std::endl;
}

int main()
{
    // pointer vs reference
    int a{5};
    int b{10};

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    // as pointers
    Swap(&a, &b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    // as reference
    Swap(a, b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "---pointer and reference exeptions----" << std::endl;

    int x{5};
    // with pointers we can handle possible errors, like nullptrs
    Print(nullptr);
    Print(NULL);
    Print(&x);
    // with references we can not handle null values
    Print(x);
    return 0;
}