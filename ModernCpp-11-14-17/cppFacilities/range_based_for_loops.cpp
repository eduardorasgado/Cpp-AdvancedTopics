#include <iostream>
#define space() (std::cout << std::endl)

int main()
{
    //
    int arr[] = {1,2,3,4,5,6,7,8};

    std::cout << (sizeof(arr)/sizeof(*arr)) << std::endl;
    // traditional way for loop
    for(int i = 0;i < (int)(sizeof(arr)/sizeof(*arr));++i)
    {
        std::cout << arr[i] << " ";
        if(i == (int)((sizeof(arr)/sizeof(*arr))-1)) space();
    }

    // c++11 for loop
    for(auto &x : arr)
    {
        // it is not read only, we can modify the value
        x = x*2;
        std::cout << x << " ";
    }
    space();

    // c++11 for loop: initializer list as range
    for(const auto &x : {2,4,6,8,10})
    {
        std::cout << x << " ";
    }
    space();
    return 0;
}