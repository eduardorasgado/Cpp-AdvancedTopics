//
// Created by cheetos on 8/11/18.
//

#include "Integer.h"

Integer::Integer() {}

Integer::Integer(int value)
{
    m_pIn = new int(value);
}

// copy constructor
Integer::Integer(const Integer & obj)
{
    // performing copy constructor
    m_pIn = new int(*obj.m_pIn);
}

Integer::~Integer()
{
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
