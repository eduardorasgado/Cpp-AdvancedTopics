#include <iostream>

#define space() (std::cout << "---------" << std::endl)

// returns a R value
int Add(int x, int y)
{
    return x + y;
}

// returns a L value
int& transform(int &x)
{
    x *= x;
    return x;
}

void Print(int &x)
{
    //
    std::cout << "Print(int &x)" << std::endl;
}

void Print(const int &x)
{
    //
    std::cout << "Print(const int &x)" << std::endl;
}

// this function takes an r value reference as param
void Print(int &&x)
{
    //
    std::cout << "Print(int &&x)" << std::endl;
}

int main() {
    // L values, R values, R value references

    // x, y and z are l-values and 5,10,8 are r-values
    int  x = 5;
    int y = 10;
    int z = 8;

    // Expression returns r-value
    int result = (x + y) * z;

    // expression returns l-value
    ++x = 6;

    /*
     *  R VALUE REFERENCES(new in C++11)
     *      A reference created to a temporary
     *      Represents a temporary
     *      Created with && operator
     *      Cannot point to l-values
     *      R value refereces always bind to temporaries
     *      L value reerences always bind to L values
     *
     * */

    int &&r1 = 10; // R value references
    int &&r2 = Add(2, 5); // Add returns by value(temporary)
    int &&r3 = 7 + 2; // Expression returns a temporary

    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;
    std::cout << r3 << std::endl;

    // r value reference cannot be assigned to reference a l value
    int xx = 4;
    //int &&rx = xx;

    // transform is returning an l-value
    int &ref = transform(xx);

    //--------------------------
    // pointer to get the allocation of the alias of xx transformed
    int *p_to_ref = &ref;

    std::cout <<  "ref: " << ref << std::endl;
    std::cout << "ref allocation address: " << p_to_ref << std::endl;
    //--------------------------

    // r value reference which is an integer constant
    const int &ref2 = 367;

    std::cout << ref2 << std::endl;
    //-------
    space();

    int intValue = 555;
    Print(intValue);

    const int constInt = 444;
    Print(constInt);

    // temporary always bind r value references
    // if there is no a function overloading that handles r value reference param
    // the Print function will be called is the one who handles (const int &x)
    Print(22);

    return 0;
}