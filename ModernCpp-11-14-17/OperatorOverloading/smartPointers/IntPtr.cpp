//
// Created by cheetos on 17/11/18.
//

#include "IntPtr.h"
#include "Integer.h"

IntPtr::IntPtr(Integer *p): m_p{p} {}

IntPtr::~IntPtr()
{
    std::cout << "~IntPrt()" << std::endl;
    delete m_p;
}

Integer* IntPtr::operator->()
{
    // to be able to use p->getValue()
    return m_p;
}

Integer& IntPtr::operator*()
{
    // to be able to use (*p)->getValue()
    return *m_p;
}