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

        // base constructor
        Integer(int value, double d_value): m_value{value}, d_value{d_value}{ }

        // default for copy constructor
        //Integer(const Integer &obj): Integer(obj.m_value, 0){}
        Integer(const Integer &) = default;

        ~Integer() { }

        void showNum() const
        {
            std::cout << m_value << std::endl;
            std::cout << d_value << std::endl;
        }

        // delete keyword is a way to make unavailable a constructor, copy constructor
        // or a operation

};

inline void space() { std::cout << "------" << std::endl; }

int main() {
    Integer i1;
    i1.showNum();
    space();

    Integer i2{3};
    i2.showNum();
    space();

    Integer ii{3,4.567};
    ii.showNum();
    space();

    Integer i3{ii};
    i3.showNum();

    return 0;
}