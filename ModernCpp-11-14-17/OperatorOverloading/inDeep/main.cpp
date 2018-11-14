#include <iostream>
#include <memory>
#include "Integer.h"
#include <cstdlib>
#include <cstdlib>

inline void showData(Integer& i)
{
    std::cout << i.getValue() << std::endl;
}

inline void showData2(Integer i)
{
    std::cout << i.getValue() << std::endl;
}

Integer operator+(const Integer &x, int y)
{
    // operator overloading fot Integer + int
    Integer temp{x.getValue() + y};
    return temp;
}

int main() {
    Integer i1{45};
    Integer i2{10};

    // calling sum operator
    Integer i3{i1 += i2};
    std::cout << "+= here:" << std::endl;
    showData(i3);

    //pre incremental operator
    showData(++i3);
    // post incremental operator
    showData2(i3++);
    showData(i3);

    Integer i4{i3};

    if(i3 == i4) std::cout << "i3 is equal to i4" << std::endl;
    if(!(i3 ==i2)) std::cout << "i3 is different than i2" << std::endl;

    // calling the assignation operation already overloaded
    i1 =  i4;
    showData(i1);

    // assigning the same object to itself to test if handles this
    // process work
    i2 = i2;
    showData(i2);

    // i1 now is equals to 57
    // what we do here is to move an instance i1 from the object
    // itself to a new object, it is more readable and efficient
    // than copy the object
    Integer iix = std::move(i1);
    showData(iix);
    // now i1 does not exist anymore, because std::move()
    // force the compiler to treat it as a r-value
    // it means to convert i1 into a temporary variable, then
    // assigns it to i2 through move operator=, and delete i1.

    //showData(i1);

    //------------------------------
    std::cout << "--------Global Overloads---------" << std::endl;

    Integer a(1), b(42);
    //Integer b{3};
    // it is possible to sum an object and a primitive type
    // because compiler executes something called type conversion
    // primitive should be on the right side this thing takes effect
    Integer sum = (a + 5);
    // this will cause an error
    //Integer sum2 = 6 + b;
    showData(sum);

    return 0;
}