//
// Created by cheetos on 11/11/18.
//

#include "Integer.h"

int Integer::count = 0;

Integer::Integer(): m_pInt{new int(0)}
{
    std::cout << "Integer()" << std::endl;
}

Integer::Integer(int value): m_pInt{new int(value)}
{
    std::cout << "Integer(int)" << std::endl;
}

Integer::Integer(const Integer &obj)
{
    m_pInt = new int(*obj.m_pInt);
}

Integer::~Integer() {
    std::cout << "~Integer()" << std::endl;
    delete m_pInt;
}

int Integer::getValue() const {
    return *m_pInt;
}

void Integer::setValue(int value) {
    *m_pInt = value;
}

int Integer::getCount()
{
    return count;
}

Integer Integer::operator+(const Integer &a) const
{
    Integer tmp{*m_pInt + *a.m_pInt};
    return tmp;
}