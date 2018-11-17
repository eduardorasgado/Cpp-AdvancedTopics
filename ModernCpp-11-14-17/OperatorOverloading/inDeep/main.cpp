#include <iostream>
#include <utility> // here is where std::move is
#include "Printer.h"
#include "Integer.h"

inline void showData(Integer& i)
{
    std::cout << i.getValue() << std::endl;
}

inline void showData2(Integer i)
{
    std::cout << i.getValue() << std::endl;
}

// to add Integer + int
Integer operator+(const Integer &x, int y)
{
    // global operator overloading
    Integer temp{x.getValue() + y};
    return temp;
}

// to add int + Integer
Integer operator+(int x, const Integer &y)
{
    // global operator overloading
    Integer temp{x + y.getValue()};
    return temp;
}

// friend function
std::ostream& operator<<(std::ostream& out, const Integer &obj)
{
    // global operator << overloading
    //out << obj.getValue();
    out << *obj.m_pInt;
    return out;
}

std::istream& operator>>(std::istream& in, Integer &obj)
{
    // global operator >> overloading
    int x; // temporal variable
    in >> x;
    *obj.m_pInt = x;
    return in;
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

    Integer sum2 = (2 + b);

    showData(sum2);

    // calling global operator overloaded << ostream
    std::cout << "global << overloaded: " << sum << std::endl;

    showData(a);
    std::cout << "Please insert new value to Integer a: ";
    // calling global operator >> overloaded
    std::cin >> a;
    showData(a);

    std::cout << "a int value is(calling its operator () function): ";
    // invoking the operator function
    a();

    return 0;
}