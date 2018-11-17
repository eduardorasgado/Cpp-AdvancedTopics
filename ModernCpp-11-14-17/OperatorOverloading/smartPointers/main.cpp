#include <iostream>
#include "Integer.h"
#include "IntPtr.h"
#include <utility>

//----------------------
inline void showInteger(Integer &i)
{
    std::cout << i.getValue() << std::endl;
}

inline void showInteger2(Integer i)
{
    std::cout << i.getValue() << std::endl;
}

Integer operator+(int x, Integer& obj)
{
    // global operator overloaded
    // int + Integer addition
    Integer temp{x + *obj.m_pInt};
    return temp;
}

void equalsTo(Integer&obj1, Integer &obj2)
{
    if(obj1 == obj2)
    {
        std::cout << "Son iguales" << std::endl;
    }
    else {
        std::cout << "Son distintos" << std::endl;
    }
}

//------------------------------------

void showInteger(Integer *p)
{
    std::cout << p->getValue() << std::endl;
}

void showInteger(IntPtr &p)
{
    std::cout << p->getValue() << std::endl;
}

void CreateInteger()
{
    //Integer *p = new Integer;

    // Creating an IntPtr object statically and
    // creating and Integer dinamically inside,
    // we know statics objects are automatically deleted
    // so, when IntPtr is deleted it calls its destructor and
    // destructor can be coded to delete the pointer to our
    // dynamic object

    // p is a smart pointer. It behaves like a pointer but it automatically
    // freezes the memory
    // p is a local object but it behaves like a dynamically
    // allocated object
    IntPtr p = new Integer;

    p->setValue(3);

    showInteger(p);
    // actually when the function ends, p will be destroyed
    // automatically, and new Integer created will be deleted
    // in the p destructor, so we can get rid of this:
    //delete p;
}

int main() {
    Integer i1{6};
    showInteger(i1);
    Integer i2{i1};
    showInteger(i2);
    Integer i3{std::move(i2)};
    showInteger(i3);
    Integer i4 = i1+i3;
    showInteger(i4);
    // declared on class using operator+(int)
    Integer i5 = i4+10;
    showInteger(i5);
    // global ooperator overloaded
    Integer i6 = 2+i5;
    showInteger(i6);
    showInteger(++i6);
    // no change
    showInteger2(i6++);
    // now change can be seen
    showInteger(i6);
    showInteger(--i1);
    showInteger2(i1--);
    showInteger(i1);
    equalsTo(i6, i5);
    Integer i3Copy{i3};
    equalsTo(i3, i3Copy);
    std::cout << "-----" << std::endl;
    showInteger(i6);
    i6 =  i4;
    showInteger(i6);
    showInteger(i3);
    // efficient, elegant and fast way to get a copy of an instance
    i3Copy = std::move(i6);
    showInteger(i3Copy);
    i5();
    std::cout << "-----smart pointers-----" << std::endl;
    // Resource adquisition and initialization
    CreateInteger();

    std::cout << "----------------" << std::endl;

    return 0;
}