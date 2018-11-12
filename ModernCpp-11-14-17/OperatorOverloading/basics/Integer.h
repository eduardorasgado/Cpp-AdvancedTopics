//
// Created by cheetos on 11/11/18.
//

#ifndef BASICS_INTEGER_H
#define BASICS_INTEGER_H


class Integer {
    private:
        int *m_pInt;

    public:
        Integer();
        Integer(int value);
        Integer(const Integer &obj);

        ~Integer();

        int getValue() const;
        void setValue(int value);

};


#endif //BASICS_INTEGER_H
