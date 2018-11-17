#include <iostream>
#include "Integer.h"
#include "IntPtr.h"
#include "Utilities.h"
#include <utility>
#include <memory> // stl smart poiinters

Integer operator+(int x, Integer& obj)
{
    // global operator overloaded
    // int + Integer addition
    Integer temp{x + *obj.m_pInt};
    return temp;
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

void Process(std::unique_ptr<Integer> ptr)
{
    std::cout << ptr->getValue() << std::endl;
}

void Process2(std::unique_ptr<Integer> &ptr)
{
    std::cout << ptr->getValue() << std::endl;
}

// UNIQUE POINTER
void CreateDynamicIntegerSafelyUnique()
{
    //using memory library
    // smart unique pointer is used when we dont wanna
    // share any object resource
    // its copy constructor is deleted
    // just support move semantics
    std::unique_ptr<Integer> p(new Integer);
    // does not support copy operations
    //auto p2{p};
    p->setValue(2000);
    Process2(p);

    p->setValue(5000);
    // delegating new privileges to Process to manage
    // unique_ptr
    // after this function p will not be available anymore
    Process(std::move(p));
}

// SHARED POINTER
void CreateDynamicIntegerSafelyShared()
{
    // a shared smart pointer
    // can share resources
    std::shared_ptr<Integer> p(new Integer);
    p->setValue(12345);
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

    std::cout << "--------unique ptr--------" << std::endl;

    CreateDynamicIntegerSafelyUnique();
    std::cout << "-------shared ptr---------" << std::endl;
    CreateDynamicIntegerSafelyShared();

    std::cout << "----------------" << std::endl;

    return 0;
}