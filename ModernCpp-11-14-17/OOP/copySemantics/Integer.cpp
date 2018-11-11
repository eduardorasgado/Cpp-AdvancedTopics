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

// constructor to do deep copy of pointer
Integer::Integer(const Integer &obj)
{
    std::cout << "Integer(const Integer &" << std::endl;
    m_pInt = new int(*obj.m_pInt);
}

Integer::~Integer()
{
    std::cout << "Destructed" << std::endl;
}

