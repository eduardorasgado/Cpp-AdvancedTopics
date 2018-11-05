#include <iostream>
#include <cstdlib>
#include <cstring>

void NewArray()
{
    // allocating five elements
    int *p = new int[5];

    // introducing values to the array
    for(int i = 0; i < 5; ++i)
    {
        *(p+i) = i;
    }
    // showing those values
    for(int i = 0;i < 5; ++i)
    {
        std::cout << *(p+i) << " ";
        if(i == 4) std::cout << std::endl;
    }

    // deallocating memory the pointer is using, for arrays it is important
    // to use brackets, with this compiler will know it has to deallocate an array
    // instead just one value
    delete []p;
    // then in this case we do not need to reassing as nullptr
    //p = nullptr;

    // we can create a dynamic array with uniform initialization as well
    int N = 8;
    int *pArr = new int[N]{1,2,3,4,5,6,7,8};

    for (int j = 0; j < N; ++j) {
        std::cout << *(pArr+j) << " ";
    }
    std::cout << std::endl;

    delete []pArr;
}

void String()
{
    // whenever we want to allocate memory for string
    // we should include an extra byte

    // allocating 4 bytes
    char *p = new char[4];
    // we are using three bytes, last is a null term value
    // introducing values into the pointer
    strcpy(p, "C++");

    std::cout << p << std::endl;

    delete []p;
}

int main()
{
    // new for allocating dynamic arrays

    NewArray();
    String();

    return 0;
}