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
        friend Integer operator+(int x, Integer& obj);
        Integer& operator++(); // preincremental
        // int in params is a must to be interpreted as post incremental
        Integer operator++(int); // post  incremental
        Integer& operator--();  // predecremental
        Integer operator--(int); // post decremental
        bool operator==(const Integer&);
        // assignation operator via deep copy
        Integer& operator=(const Integer&);
        // assignation operator for std::move
        Integer&operator=(Integer&&);

};