/*
 * COPY AND MOVE SEMANTICS
 *
 * Copy implementation through copy constructor
 * Copy of the object is created
 * Wasteful in case copy is created from a temporary
 *
 * */

/*
 * -----RULE OF 5
 *
 *  All should be defined if a user implements any of the following
 *
 *      Destructor
 *      Copy Constructor
 *      Copy assignment operator
 *      Move constructor
 *      Move assignment operator
 *
 *  Then if you implements copy semantics it is recomended to
 *  develop move semantics too
 * */

/* AS NOTES:
 *  Differences between copy constructor and assignment operator
 *
 *   t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);"
 *   Test t3 = t1;  // calls copy constructor, same as "Test t3(t1);"
 * */

#include <iostream>
#include <memory>
#include "Integer.h"
#include "Float.h"

using namespace ACME;

// returns a temporary Integer/ r-value
Integer Add(const Integer &a, const Integer &b)
{
    Integer temp;
    temp.setValue(a.getValue() + b.getValue());
    return temp;
}

Float Add(const Float &a, const Float &b)
{
    Float temp;
    temp.setValue(a.getValue() + b.getValue());
    return temp;
}

void Process(Float val)
{
    //
}

int main() {
    // Move semantics
    Integer a(1), b(3);

    std::cout << a.getValue() << std::endl;

    // in this expression: add returns a temporary Integer
    // object, we take the value with its memeber function getValue
    // and then Integer is deleted from memory
    a.setValue(Add(a, b).getValue());

    std::cout << a.getValue() << std::endl;

    /* FLOAT EXAMPLE AND ------- MOVE SEMANTICS---- */
    std::cout << "-------------" << std::endl;

    Float f1;
    f1.showValue();

    Float f11{1.4f};

    Float f2{4.6f};
    f2.showValue();

    std::cout << "Copy of Float: " << std::endl;
    // this calls the copy constructor
    auto f3(f2);
    f3.setValue(Add(f11, f2).getValue());
    f3.showValue();
    std::cout << "size of pointer: " << sizeof(f3.getValue()) << std::endl;

    // this process calls the copy constructor too
    Process(f1);


    std::cout << "-----------" << std::endl;
    /*now lets see how to use move semantics*/

    // calls a copy constructor
    auto  f4(f2);
    // calls the
    /*--------move constructor---------*/
    // after we use std::move(f2)
    // f2 is not available again, it was converted in a r-value
    // so nOw it is a temporary object to be copied
    // using MOVE CONSTRUCTOR and its value was converted in a nullptr
    auto f5(std::move(f2));

    // f2 not available anymore
    //f2.showValue();

    // invokes copy cosntructor
    Process(f1);
    // invokes move constructor
    // set a nullptr to f1 value within
    // and call the destructor of f1
    Process(std::move(f1));

    // then f1 has a nullptr
    if(f1.getPtr() == nullptr)
        std::cout << "Actually f1 has a nullptr" << std::endl;

    return 0;
}