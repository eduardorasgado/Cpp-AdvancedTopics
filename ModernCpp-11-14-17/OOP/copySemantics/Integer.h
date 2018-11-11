#pragma once

#include <iostream>

class Integer
{
        int *m_pInt;

    public:
        Integer();
        Integer(int value);
        Integer(const Integer&);

        ~Integer();

        int getValue() const;
        void setValue(int value);
};