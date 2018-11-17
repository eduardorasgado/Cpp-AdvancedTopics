//
// Created by cheetos on 16/11/18.
//

#include "Integer.h"

Integer::Integer(): m_pInt{new int(0)} {}

Integer::Integer(int value): m_pInt{new int()} {}

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


