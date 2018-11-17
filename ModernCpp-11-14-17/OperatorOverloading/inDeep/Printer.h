//
// Created by cheetos on 16/11/18.
//

#ifndef INDEEP_PRINTER_H
#define INDEEP_PRINTER_H

#include <iostream>

// forward declaration to be able to use the Integer class inside
// this header

class Integer;

class Printer {
        bool is_printing;

    public:
        Printer();
        void PrintInteger(Integer &obj);
};


#endif //INDEEP_PRINTER_H
