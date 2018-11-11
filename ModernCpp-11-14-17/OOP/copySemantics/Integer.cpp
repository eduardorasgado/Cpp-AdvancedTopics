//
// Created by cheetos on 11/11/18.
//

#include "Integer.h"

Integer::Integer(): m_pInt{new int(0)}
{
    std::cout << "Integer()" << std::endl;
}

Integer::Integer(int value): m_pInt{new int(value)}
{
    std::cout << "Integer(int)" << std::endl;
}

/*
 * In this example project, this constructor is called when
 * Integer temporary object is created in main.cpp,
 * eventually when create a copy temporary copy, things will go bad
 *
 *  temporary object      assignated object
 *
 *      *m_pInt  <--pointing---  *m_pInt
 *
 *  BUT: when temporary is deleted:
 *
 *       deleted <--pointing--- *m_pInt
 *
 *  then program could crash.
 *
 *  NOTE:
 *  Named Return Value Optimization.
 *
 *  Modern C++ compilers automatically apply NRVO.
 *  The compiler does not create a temporary from the return value,
 *  instead it uses the same variable to get the value.
 *
 *  So wont see copy cosntructor uses this thing, but a way to
 *  avoid this bug is to specify the 2) copy constructor
 * */

/* 1) */
// constructor to do deep copy of pointer
Integer::Integer(const Integer &obj)
{
    std::cout << "Integer(const Integer &)" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

/*
 * A solution for the bug described above:
 *
 * Create a copy constructor based on a r-value reference param
 * and assigning the copy constructor pointing to nullptr after
 * deletes, it will avoids "delete" crashes in temporary Integer
 * handling
 * */

/* 2) */
Integer::Integer(Integer &&obj)
{
    // a method to avoid create a copy when we uses a temporary object
    // and dont want destructor crashes
    std::cout << "Integer(Integer &&)" << std::endl;
    // shallow copy -> coopy from the temporary object to the target
    // object, avoiding data in temporary object pointer dont be available
    // after its destruction
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

Integer::~Integer()
{
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
}

int Integer::getValue() const
{
    return *m_pInt;
}

void Integer::setValue(int value)
{
    *m_pInt = value;
}
