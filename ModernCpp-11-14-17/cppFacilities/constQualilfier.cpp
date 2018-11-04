#include <iostream>

int main()
{
    /* const: creates a variable that is constant
    Value cannot be modified
    Attempt to modify will cause compilation error
    Qualified to a declaration, bit always needs an initializer
    Replaces C macros
    Commonly used with references
    const <type> <variable> {initializer}
    */
    const float PI = 3.14f;

    float radius{};
    std::cout << "Circle's radius: ", std::cin >> radius;

    float area = PI * radius * radius;
    float circumference = PI * 2 * radius;

    std::cout << "Area is: " << area << std::endl;
    std::cout << "Circumference is: " << circumference << std::endl;
    return 0;
}