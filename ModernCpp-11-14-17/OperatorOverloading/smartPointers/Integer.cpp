//
// Created by cheetos on 16/11/18.
//

#include "Integer.h"

Integer::Integer(): m_pInt{new int(0)} {}

Integer::Integer(int value): m_pInt{new int(value)} {}

// copy constructor
Integer::Integer(const Integer &obj)
{
    //deep copy
    m_pInt = new int(*obj.m_pInt);
}

// move constructor
Integer::Integer(Integer &&obj)
{
    // shallow copy
    if(obj.m_pInt != nullptr)
    {
        // just reassigning the memory location because we are just
        // moving the location from one Integer object to another object
        m_pInt = obj.m_pInt;
        // obj will be deleted so we need to set a null pointer to avoid
        // destructor crashes
        obj.m_pInt = nullptr;
    }
}

Integer::~Integer()
{
    delete m_pInt;
}

// setters and getters
void Integer::setValue(int value)
{
    if(sizeof(int) == sizeof(value)) *m_pInt = value;
}

int Integer::getValue() { return *m_pInt; }

Integer Integer::operator+(const Integer&obj)
{
    Integer temp{*obj.m_pInt + *m_pInt};
    return temp;
}

Integer Integer::operator+(int value)
{
    Integer temp{*m_pInt + value};
    return temp;
}

Integer& Integer::operator++()
{
    // more efficient than post incremental operator,  because it does
    // not make any copy
    (*m_pInt)++;
    // reurning same object
    return *this;
}

Integer Integer::operator++(int)
{
    Integer temp{*this};
    (*m_pInt)++;
    // returning the copy without any changes
    return temp;
}