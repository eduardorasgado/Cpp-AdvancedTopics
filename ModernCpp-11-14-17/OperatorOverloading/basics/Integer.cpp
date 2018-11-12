//
// Created by cheetos on 11/11/18.
//

#include "Integer.h"

int Integer::count = 0;

Integer::Integer(): m_pInt{new int(0)}
{
    count++;
    std::cout << "Integer()" << std::endl;
}

Integer::Integer(int value): m_pInt{new int(value)}
{
    count++;
    std::cout << "Integer(int)" << std::endl;
}

Integer::Integer(const Integer &obj)
{
    count++;
    m_pInt = new int(*obj.m_pInt);
    std::cout << "Integer(const Integer &)" << std::endl;
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

// can be invoke as ++obj
Integer& Integer::operator++()
{
    (*m_pInt)++;
    // returning the actual object invokes the member function
    // reassigning same oobject
    return *this;
}

// postincremental operator obj++
Integer Integer::operator++(int)
{
    // invokes copy constructor of same object
    Integer tmp{*this};
    (*m_pInt)++;
    // want to simulate the behavior of postincremental operator
    // so return the temporary object without the increment
    // and then after program invokes this function
    // the increment will be reflected on the original object
    return tmp;
}

bool Integer::operator==(const Integer &obj)
{
    return (*m_pInt == *obj.m_pInt);
}