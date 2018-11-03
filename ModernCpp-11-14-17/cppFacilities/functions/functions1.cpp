//
// Created by cheetos on 2/11/18.
//

#include <iostream>
#include "Math.h"

int main()
{
    // FUNCTIONS

    // sequential coding
    int x, y;
    std::cin >> x >> y;
    int result = x + y;
    std::cout << "Result1 is: " << result << std::endl;
    std::cout << "-----------------" << std::endl;

    // Better way
    int result2 = Add(x, y);
    std::cout << "Result2 is: " << result2 << std::endl;

    return 0;
}
