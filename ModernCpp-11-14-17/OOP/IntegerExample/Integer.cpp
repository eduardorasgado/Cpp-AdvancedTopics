//
// Created by cheetos on 8/11/18.
//

#include "Integer.h"

Integer::Integer() {
    std::cout << "created default" << std::endl;
}

Integer::Integer(int value)
{
    m_pIn = new int(value);
    std::cout << "created w/value" << std::endl;
}

// copy constructor
Integer::Integer(const Integer & obj)
{
    // performing copy constructor
    m_pIn = new int(*obj.m_pIn);
}

Integer::~Integer()
{
    // it is important do deallocate the dynamic integer
    delete m_pIn;
}

int Integer::getValue() const
{
    return *m_pIn;
}

void Integer::setValue(int value)
{
    //
    *m_pIn = value;
}
