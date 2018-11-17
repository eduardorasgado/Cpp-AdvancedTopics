//
// Created by cheetos on 17/11/18.
//

#ifndef SMARTPOINTERS_INTPTR_H
#define SMARTPOINTERS_INTPTR_H

#include <iostream>

// forward declaration
class Integer;

class IntPtr
{
    private:
        Integer *m_p;

    public:
        IntPtr(Integer*);
        ~IntPtr();
        // arrow operator overloading to be able to access
        // Integer methods inside the IntPtr instances
        Integer* operator->();
        // * operator overloaded
        Integer& operator*();
};


#endif //SMARTPOINTERS_INTPTR_H
