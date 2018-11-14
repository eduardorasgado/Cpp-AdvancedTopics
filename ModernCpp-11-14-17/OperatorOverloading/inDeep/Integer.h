#pragma once

#include <iostream>

class Integer
{
    private:
        int *m_pInt;

    public:
        Integer();
        Integer(int);
        // copy constructor
        Integer(const Integer&);
        // move constructor
        Integer(Integer &&);

        ~Integer(); // Destructor

        // handlers
        Integer(double) = delete;
        Integer(float) = delete;

        // getters and setters
        int getValue() const;
        void setValue(int value);

        // operator overloading
        int operator+(const Integer&);
        // pre-incremental operator
        Integer &operator++();
        // post-incremental operator
        Integer operator++(int);
        // comparison operator
        bool operator==(const Integer&);
        // asignation operator
        Integer & operator=(const Integer&);
        // move asignation operator
        Integer& operator=(Integer &&);

};