#pragma once

#include <iostream>

class Integer
{
        int *m_pInt;

    public:
        Integer();
        Integer(int value);
        Integer(const Integer&);
        // Move semantic constructor
        Integer(Integer &&obj);

        ~Integer();

        int getValue() const;
        void setValue(int value);
};