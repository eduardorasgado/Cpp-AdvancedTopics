//
// Created by cheetos on 11/11/18.
//

#ifndef BASICS_INTEGER_H
#define BASICS_INTEGER_H

#include <iostream>

class Integer {
    private:
        int *m_pInt;
        static int count;

    public:
        Integer();
        Integer(int value);
        Integer(const Integer &obj);

        ~Integer();

        int getValue() const;
        void setValue(int value);
        static int getCount();

        // operator overloading for member function
        Integer operator+(const Integer &) const;
        // pre-incremental operator
        /*Actually, a pre incremental operator is
         * more efficient than post incremental because
         * it does not create a temporary object*/
        Integer& operator++();
        //post-incremental operator
        Integer operator++(int);
        bool operator==(const Integer &);
};


#endif //BASICS_INTEGER_H
