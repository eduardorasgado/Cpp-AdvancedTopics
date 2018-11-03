//
// Created by cheetos on 3/11/18.
//

#include <iostream>

template <typename T>
void showingPointer(T*);

// a void pointer, can be used in some special cases
void showingVoidPointerInt(void *&vp);
void showingVoidPointerFloat(void *&vp);
void showingVoidPointerDouble(void *&vp);

int main()
{
    int x{ 0 };
    float f{ 0.2f };
    double d{6436.36363 };
    // pointer to a reference

    // initializing safely
    int *px{nullptr};

    // assigning memory allocation
    px = &x;
    // here * is not a pointer operator anymore, now it is a derreferenciate operator
    showingPointer(px);


    std::cout << "---void pointer----" << std::endl;
    // https://www.learncpp.com/cpp-tutorial/613-void-pointers/

    // A void type poiter can be reassigned with more than one types of values
    void *vpx{nullptr};

    // declaring and showing the void pointer
    // integer type
    vpx = &x;
    // handling void pointer as a integer
    showingVoidPointerInt(vpx);

    // float type
    vpx = &f;
    showingVoidPointerFloat(vpx);

    // double type
    vpx = &d;
    showingVoidPointerDouble(vpx);

    return 0;
}

template <typename T>
void showingPointer(T* px)
{
    // showing pointer
    std::cout << "The value: " << *px  << " is located at: " << px << std::endl;
}

// handling void pointer, integer casting
void showingVoidPointerInt(void *&vp)
{
    //std::cout << *vp << std::endl; //illegal:cannot dereference a void pointer

    // if we cast our pointer to a defined type we can dereference then
    int *intPtr = static_cast<int*>(vp);

    // passing new pointer to show function
    showingPointer(intPtr);
}

// handling void pointer, float casting
void showingVoidPointerFloat(void *&vp)
{
    // if we cast our pointer to a defined type we can dereference then
    float *floatPtr = static_cast<float*>(vp);
    // passing new pointer to show function
    showingPointer(floatPtr);
}

// handling void pointer, double casting
void showingVoidPointerDouble(void *&vp)
{
    // if we cast our pointer to a defined type we can dereference then
    double *doublePtr = static_cast<double*>(vp);
    // passing new pointer to show function
    showingPointer(doublePtr);
}