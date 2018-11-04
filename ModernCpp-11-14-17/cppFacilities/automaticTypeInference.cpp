#include <iostream>
#include <algorithm>
#include <iterator>
#include <initializer_list>

int Sum(int& x, int& y)
{
    return x+y;
}

template <typename T>
void Print(T& val)
{
    std::cout << "by reference: " << val << std::endl;
}

template <typename T>
void Print(T* val)
{
    std::cout << "by pointer: " << *val << std::endl;
}

template <typename T>
void printList(std::initializer_list<T> list)
{
    for(auto v : list) std::cout << v << " ";
    std::cout << std::endl;

    // showing list using STL
    std::ostream_iterator<T> output(std::cout, " ");
    std::copy(list.begin(), list.end(), output);
    std::cout << std::endl;
}

int main()
{
    // auto keyword
    // allows the compiler to automatically infer the type from the initializer
    // the intializer is important
    auto i{10};
    auto j{5};
    auto b{4.5f};
    auto sum{i+j};
    auto addition{i+0.3f};
    auto sum2{Sum(i, j)};
    // even we can apply auto to static variables
    static auto y = 2325322722;

    Print(i);
    Print(j);
    Print(b);
    Print(sum);
    Print(addition);
    Print(sum2);
    Print(y);

    // constant and auto
    const int x = 10;
    const auto var = x;
    Print(var);

    // auto and references
    auto &var1 = x;
    Print(var1);

    // auto and pointers
    // we do not need to write the asteric now
    auto ptr = &i;
    Print(ptr);

    // auto and initializer list
    auto list = {1,2,3,4,5};
    printList(list);

    return 0;
}