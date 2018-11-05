/*
 * NAMESPACES
 *
 * Named declarative region used for declaring types
 * The types are not visible outside the namespace
 * tandard library in in std namespace
 * Prevents name clashes
 * Helps modularize code
 *
 * It is possible to nest namespaces
 *
 * Types inside a namespace have a scope
 * Cannot beaccessed outside the namespace
 * Either open the namespace or type
 *  -use the global using declarative and open the entire namespace
 *      using namespace std;
 *  -use the using declaarative and open a specific type
 *      using std::cout;
 *  -using the full qualified name
 *      std::cout << "C++" << std::endl;
 * */
#include <iostream>

namespace Average
{
    float Calculate(float x, float y)
    {
        return (x + y) / 2;
    }
}

namespace Basic
{
    float Calculate(float x, float y)
    {
        return x + y;
    }
}

using namespace Basic;

int main()
{
    // using Basic namespace
    std::cout << Calculate(4.5f, 4.6f) << "\n";

    // using declarative namespace
    std::cout << Average::Calculate(4.5f, 4.6f) << "\n";
    return 0;
}