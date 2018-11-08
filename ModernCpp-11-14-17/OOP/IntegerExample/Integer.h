#pragma once

class Integer
{
        int *m_pIn;
    public:
        Integer();
        Integer(int value);

        // copy constructor
        Integer(const Integer &obj);

        ~Integer();

        int getValue() const;
        void setValue(int value);
};