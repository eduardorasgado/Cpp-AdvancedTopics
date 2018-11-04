#include <iostream>
#include <map>
#include <memory>

// inline function through a macro
// if it is not handling correctly it will create bugs
//#define Square(A) (A*A)

// In c++ instead a macro we use inline functions

// inline keyword tells the compiler to substitute the caller of the function in
// where inline function is been using(e.g int result = Square(val) )
// and replace it with the body of the function(in compiler time)
inline int Square(int x)
{
    return x * x;
}

// new name for type pair: type definition
typedef std::pair<int, std::string> par;


int main()
{
    // creating a map using a smart pointer
    auto myMap = std::make_shared<std::map<int, std::string>>();

    // inserting elements to map
    myMap->insert(par(0, "0x200"));
    myMap->insert(par(1, "0x420"));

    //showing the map
    // creating an iterator for stl map object
    std::map<int, std::string>::iterator i = myMap->begin();
    for(i; i != myMap->end();++i) std::cout << "map[" << i->first <<"]: " << i->second << "\n";

    // inline functions
    int val = 5;
    // with inline function, the arguments passed here are firstly evaluated and then
    // passed to the function
    int result = Square(val + 1);
    std::cout << result << std::endl;

    int result2 = Square((val * 2) +1); // 11 and 11*11 = 121
    std::cout << result2 << std::endl;
    /*
    INLINE FUNCTIONS:
        -Only a request to the compiler
        -Certain functions may nto be inlined
            large functions
            functions having too many conditional statements
            recursive functions
            functions invoked through pointers
            etc
        -Diferent compilers have different rules
        - Modern compilers may automatically inline even non-inline functions
        -Excessive inlining may increase binary size

    MACROS VS INLINE
        macro is text substitution | the call is replaced with the body
        error prone due to substitution | safe to use as it has func semantics
        does not have an address     |  has an address
        difficult to use with multiple lines of code | can have multiple line of codes
    */
    return 0;
}

