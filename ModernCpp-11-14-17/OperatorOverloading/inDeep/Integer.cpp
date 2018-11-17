//
// Created by cheetos on 13/11/18.
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

// copy constructor
Integer::Integer(const Integer &obj)
{
    std::cout << "Deep copy done" << std::endl;
    // deep copy
    m_pInt = new int(*obj.m_pInt);
}

//move constructor
Integer::Integer(Integer &&obj)
{
    std::cout << "Shallow copy done" << std::endl;
    // shallow copy
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

Integer::~Integer()
{
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

int Integer::operator+=(const Integer&obj)
{
    //std::cout << *m_pInt + *obj.m_pInt << std::endl;
    return *m_pInt + *obj.m_pInt;
}

// pre incremental operator overloading
Integer& Integer::operator++()
{
    (*m_pInt)++;
    return *this;
}

//post incremental operator overloading
Integer Integer::operator++(int)
{
    // simulating native post incremental operator behavior
    Integer temp{*this};
    (*m_pInt)++;
    return temp;
}

// comparison
bool Integer::operator==(const Integer&obj)
{
    return *m_pInt == *obj.m_pInt;
}

// assignation
Integer & Integer::operator=(const Integer&obj)
{
    // in case trying to reassign object itself
    if(this != &obj)
    {
        // delete the actual pointer to avoid a memory leak
        delete m_pInt;
        m_pInt = new int(*obj.m_pInt);
    }
    return *this;
}

//move operator
// called when we try to assing a value from a non r value(l values)
// but we want to treat
/// this other value as a r value
// like this: Integer a = std::move(b)
Integer& Integer::operator=(Integer &&obj)
{
    // verify not assigning the actual object itself
    if(this != &obj)
    {
        // delete actual pointer from this object(that invokes the member func)
        // to avoid leaks
        delete m_pInt;
        // shallow copy
        m_pInt = obj.m_pInt;
        // to avoid destructor from obj crashes
        obj.m_pInt = nullptr;
    }
    return *this;
}

// operator function ()
// can be invoking like this: object()
void Integer::operator()()
{
    std::cout << *m_pInt << std::endl;
}