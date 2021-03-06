#pragma once

#include <iostream>

namespace ACME
{
    class Float
    {
        private:
            float *p_nFloat;

        public:
            Float();
            Float(float value);
            Float(const Float &);
            // -value reference copy construct
            Float(Float &&);

            ~Float();

            void setValue(float value);
            float getValue() const;
            void showValue() const;
            void showSize() const;
            float * getPtr() const;
    };
}
