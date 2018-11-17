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

        ~Integer();

        // handlers
        Integer(double) = delete;
        Integer(float) = delete;

        // setters and getters
        void setValue(int);
        int getValue();

        // operator overloading
        Integer operator+(const Integer&);
        Integer operator+(int value);
};