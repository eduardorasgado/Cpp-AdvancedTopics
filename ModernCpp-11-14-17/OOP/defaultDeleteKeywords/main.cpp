#include <iostream>

class Integer
{
        int m_value{0};
        double d_value{0};

    public:
        // default keyword is very useful when is not possible for the
        // compiler to create a default
        Integer() = default;
        //Integer(): m_value{0}{}

        // delegating constructor
        Integer(int value): Integer(value, 0){ }

        // it will denegate object creation with double param in constructor
        Integer(double) = delete;

        // base constructor
        Integer(int value, double d_value): m_value{value}, d_value{d_value}{ }

        // default for copy constructor
        //Integer(const Integer &obj): Integer(obj.m_value, 0){}
        Integer(const Integer &) = default;

        // we can make copy operation not available with delete
        //Integer(const Integer &) = delete;

        ~Integer() { }

        void showNum() const
        {
            std::cout << m_value << std::endl;
            std::cout << d_value << std::endl;
        }

        // delete keyword is a way to make unavailable a constructor, copy constructor
        // or a operation
        double* operator+=(Integer &other)
        {
            double *dSum = new double(this->d_value + other.d_value);
            return dSum;
        }

        // delete can be applied in member functions too
        double *operator-=(Integer &other) = delete;

        void setInteger(int value)
        {
            m_value = value;
        }

        void setInteger(float) = delete;
};

inline void space() { std::cout << "------" << std::endl; }

int main() {
    Integer i1;
    i1.showNum();
    space();

    Integer i2{34};
    i2.showNum();
    space();

    Integer ii{3,4.567};
    ii.showNum();
    space();

    Integer i3{ii};
    i3.showNum();
    space();

    auto *dsuma = i3+=ii;
    std::cout << "+operator: " <<  *dsuma << std::endl;

    // delete does not allow us to do this operation after
    // been assigned to operator -=
    //auto ddiff = i3-=ii;
    //std::cout << "-operator: " << * ddiff << std::endl;

    double quant = 32163663.336433;
    // not allowed because double assignation was deleted
    //Integer numberClass{quant};

    space();
    // cannot call function with float param because of delete keyword
    //i2.setInteger(144.6f);
    i2.setInteger(2);
    i2.showNum();

    return 0;
}