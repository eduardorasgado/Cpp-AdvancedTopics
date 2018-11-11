#include <iostream>

int Square(int &&x)
{
    return x * x;
}

void showing(int&val)
{
    std::cout << val << std::endl;
}
void showing( const int&val)
{
    std::cout << val << std::endl;
}

int main() {
    std::cout << "r-value reference use cases" << std::endl;

    int &&res1= Square(8);
    const int &res2 = Square(20);
    int res3 = Square(Square(5));

    // showing results
    showing(res1);
    showing(res2);
    showing(res3);

    return 0;
}