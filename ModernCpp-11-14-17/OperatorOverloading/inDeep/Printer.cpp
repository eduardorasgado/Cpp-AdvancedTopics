//
// Created by cheetos on 16/11/18.
//

#include "Printer.h"
// class that is using Printer as friend should be
// included in this cpp
#include "Integer.h"

Printer::Printer(): is_printing{false}{}


void Printer::PrintInteger(Integer &obj)
{
    // Integer class friend
    std::cout << "The actual number is: " << *obj.m_pInt<< std::endl;
}
