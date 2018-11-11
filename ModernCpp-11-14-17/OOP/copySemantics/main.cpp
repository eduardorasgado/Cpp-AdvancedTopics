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

    return 0;
}