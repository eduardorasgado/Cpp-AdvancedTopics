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

// a namespace father
namespace SortingAlgorithm
{
    void Quicksort()
    {
        //
        std::cout << "Quicksort executed" << std::endl;
    }

    void InsertionSort()
    {
        //
        std::cout << "Insertionsort executed" << std::endl;
    }

    void MergeSort()
    {
        //
        std::cout << "Mergesort executed" << std::endl;
    }

    // nested namespace: child
    namespace Comparison
    {
        void Less()
        {
            //
            std::cout << "Less sort executed" << std::endl;
        }

        void Greater()
        {
            //
            std::cout << "Greater sort executed" << std::endl;
        }
    }
}

// namespaces with no name can be declared
// but they can be access just by the actual file, it cannot be used
// ouside
namespace {
    void InternalFunction()
    {
        std::cout << "Internal function called" << std::endl;
    }
}

// It is a global declaration of namespace use
//using namespace Basic;

// declaring a global for nested specified algorithm
// notice we do not have to specify "namespace" keyword to
// declare a specific type namespace
using SortingAlgorithm::Comparison::Greater;

int main()
{
    // this namespace will be available just inside main scope
    using namespace Basic;

    // using Basic namespace
    std::cout << Calculate(4.5f, 4.6f) << "\n";

    // using declarative namespace
    std::cout << Average::Calculate(4.5f, 4.6f) << "\n";

    // sorting namespace
    SortingAlgorithm::MergeSort();

    // executing function inside the nested namespace in Sorting namespace
    SortingAlgorithm::Comparison::Less();

    // using declarative and specific type (some function we need in namespace)
    Greater();

    // calling a function from a no named namespace
    InternalFunction();

    return 0;
}