//
// Created by cheetos on 17/11/18.
//

#ifndef SMARTPOINTERS_UTILITIES_H
#define SMARTPOINTERS_UTILITIES_H

#include <iostream>
#include "Integer.h"

//----------------------
inline void showInteger(Integer &i)
{
    std::cout << i.getValue() << std::endl;
}

inline void showInteger2(Integer i)
{
    std::cout << i.getValue() << std::endl;
}


void equalsTo(Integer&obj1, Integer &obj2)
{
    if(obj1 == obj2)
    {
        std::cout << "Son iguales" << std::endl;
    }
    else {
        std::cout << "Son distintos" << std::endl;
    }
}


#endif //SMARTPOINTERS_UTILITIES_H
