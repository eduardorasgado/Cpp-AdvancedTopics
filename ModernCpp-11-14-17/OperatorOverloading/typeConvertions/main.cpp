/*
 * TYPE CONVERSIONS
 *
 * Conversions between types
 * Performed throught casts
 * Ordered by compiler(implicit) or user(explicit)
 * Explicit conversion uses casting operators
 * Conversion between:
 *      basic and basic
 *      basic and user-defined
 *      user-defined and basic
 *      user-defined and user-defined
 *
 * */
#include <iostream>

template <typename T>
inline void print(T A) { std::cout << "value: " <<A << std::endl; }
template <typename T>
inline void print(T* A) { std::cout << "value*: " << *A << std::endl; }
inline void printString(std::string A) { std::cout << A << std::endl; }

// 1) CONST CAST
class Person
{
        int age{18};

    public:
        Person() {}
        Person(int age): age{age} {}
        ~Person() {}

        // This is a constant function so we cannot change age value
        // but we will do because of const_cast
        void notChangeAge() const
        {
            (const_cast<Person*>(this))->age = 20;
        }
        int getAge() const
        {
            return age;
        }
};

//2) CONST CAST
float changeConstant(float* ptr) // note this function does not receive const pointer
{
    return *ptr + 10;
}

int main() {
    int a = 65, b = 2;
    // c style cast
    //float f = (float) a/b;
    /*static cast*/
    // c++11 static cast
    float f = static_cast<float>(a)/b;
    print(f);

    // cast to reference

    // C style cast
    // this will leads to bug, because pointer types are not convertible
    //char *p = (char*)&a;

    // this will deny the convertion
    //char *p = static_cast<char*>(&a);

    /*reinterpret_cast*/
    // allows casting between what ever cast
    // if there are any qualifiers in the source values they will
    // not be discarted
    char *p = reinterpret_cast<char*>(&a);
    print(p);

    // c style cast discard the qualifiers
    const int x =1;
    float *px = (float*)&x;
    print(px);
    // now constant qualifier was ignored and value
    *px = 55;
    print(px);

    const int y = 234;
    // a safe way to perform a constant cast
    // const_cast does not let you to change the type of the constant value
    int *py2 = const_cast<int*>(&y);
    print(py2);
    *py2 = 1000;
    print(py2);

    //------------
    printString("------More in deep-----");

    printString("CONST CAST");

    /* CONST CAST
     * const_cast is used to cast away the constness of variables.
     * Following are some interesting facts about const_cast.
     *
     *  1) const_cast can be used to change non-const class members
     *  inside a const member function.
     *
     *  2) const_cast can be used to pass const data to a function
     *  that doesn’t receive const.
     *
     *  3) It is undefined behavior to modify a value which is
     *  initially declared as const.
     *
     *  4)const_cast is considered safer than simple type casting.
     *  It’safer in the sense that the casting won’t happen if
     *  the type of cast is not same as original object.
     *
     *   See:
     *   https://www.geeksforgeeks.org/const_cast-in-c-type-casting-operators/
     * */

    // 1)
    Person p1{};
    print(p1.getAge());
    p1.notChangeAge();
    print(p1.getAge());

    // 2)
    const float yearAverage = 100.6f;
    const float *yAptr = &yearAverage;
    // passing a constant pointer to a function just take simple pointers
    // converting const float to float pointer
    float *simpleFP = const_cast<float*>(yAptr);
    print(changeConstant(simpleFP));
    // it wont let me do like this
    //print(changeConstant(yAptr));

    printString("REINTERPRET CAST");

    /*
     * It is used to convert one pointer of another pointer of any type,
     * no mather either the class is related to each other or not.
     * It does not check if the pointer type and data pointed by the pointer
     * is same or not
     * It takes the source pointer variable as parameter
     *
     * PURPOSES:
     *  reinterpret_cast is a very special and dangerous type of casting operator.
     *  And is suggested to use it using proper data type i.e,(pointer data type
     *  should be same as original data type
     *
     *  It can typecast any pointer to any other data type.
     *
     *  It is used when we want to work with bits
     *
     *  If we use this type of cast then it becomes a non-portable product.
     *  So, it is sugested not to use this concept unless required.
     *
     *  It is only used to typecast any pointer to its original type
     *
     *  Boolean value will be converted into integer value i.e,
     *  0 for false, 1 for true
     * */

    int *pp = new int(65);
    char *ch = reinterpret_cast<char*>(pp);
    print(pp);
    print(ch);
    std::cout << pp << std::endl;
    std::cout << ch << std::endl;

    struct myStruct
    {
        int x;
        int y;
        char c;
        bool b;
    };


    return 0;
}