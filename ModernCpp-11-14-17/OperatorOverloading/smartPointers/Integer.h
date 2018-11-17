#pragma once

class Integer
{
        int *m_pInt;

    public:
        Integer();
        Integer(int value);
        //copy constructor
        Integer(const Integer&);
        // mover constructor
        Integer(Integer &&);

};