//
// Created by cheetos on 16/11/18.
//

#include "Integer.h"

inline void printer(std::string text){ std::cout << text << std::endl; }

Integer::Integer(): m_pInt{new int(0)} { printer("Integer()");}

Integer::Integer(int value): m_pInt{new int(value)} { printer("Integer(int)"); }

// copy constructor
Integer::Integer(const Integer &obj)
{
    printer("Integer(const Integer&)");
    //deep copy
    m_pInt = new int(*obj.m_pInt);
}

// move constructor
Integer::Integer(Integer &&obj)
{
    printer("Integer(Integer &&)");
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
    printer("~Integer()");
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

Integer& Integer::operator--()
{
    (*m_pInt)--;
    return *this;
}

Integer Integer::operator--(int)
{
    Integer temp{*this};
    (*m_pInt)--;
    return temp;
}

bool Integer::operator==(const Integer &obj)
{
    return (*m_pInt == *obj.m_pInt);
}

Integer& Integer::operator=(const Integer &obj)
{
    if(this != &obj)
    {
        // deleting possible existing pointer, to avoiding leaks
        delete m_pInt;
        m_pInt = new int(*obj.m_pInt);
    }
    return *this;
}

Integer& Integer::operator=(Integer &&obj)
{
    // for std::move
    if(this != &obj)
    {
        // deallocate the pointer
        delete m_pInt;
        // shallow copy, taking the memory allocation from pointer of obj._mpInt
        // to actual pointer
        m_pInt = obj.m_pInt;
        // lets change memory obj is pointing because if we delete it
        // it will delete the data in memory allocation so we might not have
        // available the data to be used in this object.
        obj.m_pInt = nullptr;
    }
    return *this;
}

void Integer::operator()()
{
    std::cout << *m_pInt << std::endl;
}