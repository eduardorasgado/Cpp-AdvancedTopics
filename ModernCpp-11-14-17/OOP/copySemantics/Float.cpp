//
// Created by cheetos on 11/11/18.
//

#include "Float.h"

namespace ACME
{
    Float::Float(): p_nFloat{new float(0.f)} {
        std::cout << "Float()" << std::endl;
    }

    Float::Float(float value): p_nFloat{new float(value)} {
        std::cout <<  "Float(float)" << std::endl;
    }

    // copy constructor
    Float::Float(const Float &obj) {
        std::cout << "Float(const Float&)" << std::endl;
        p_nFloat = new float(*obj.p_nFloat);
    }

    // copy constructor to avoiding destructor crash from
    // copy objects
    Float::Float(Float &&obj) {
        std::cout << "Float(Float&&)" << std::endl;
        // shallow copy
        // copying the value inside obj's pointer
        p_nFloat = obj.p_nFloat;
        // avoiding something in delete crashes in the obj object
        obj.p_nFloat = nullptr;
    }

    Float::~Float() {
        std::cout << "~Float()" << std::endl;
        delete p_nFloat;
    }

    void Float::setValue(float value) {
        *p_nFloat = value;
    }

    float Float::getValue() const
    {
        return *p_nFloat;
    }

    void Float::showValue() const {
        std::cout << *p_nFloat << std::endl;
    }

}