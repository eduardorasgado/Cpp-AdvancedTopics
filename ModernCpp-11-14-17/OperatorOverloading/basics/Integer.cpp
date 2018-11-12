//
// Created by cheetos on 11/11/18.
//

#include "Integer.h"

Integer::Integer(): m_pInt{new int(0)} {}

Integer::Integer(int value): m_pInt{new int(value)} {}

Integer::Integer(const Integer &obj)
{
    m_pInt = new int(*obj.m_pInt);
}

Integer::~Integer() {
    delete m_pInt;
}

int Integer::getValue() const {
    return *m_pInt;
}

void Integer::setValue(int value) {
    *m_pInt = value;
}
