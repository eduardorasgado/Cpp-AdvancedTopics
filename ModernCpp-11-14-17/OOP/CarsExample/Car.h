#pragma once

#include <iostream>

class Car
{
    private:
        // uniform initialization
        // non static data members initialization
        float fuel{0};
        float speed{0};
        int passagers{0};
        std::string slots[3] = {"pop", "zedonia", "garbage"};
        char *p{};
        //auto i = 5; // but now we cannot use auto here

    public:
        Car(); // Constructor
        // constructor overloading
        Car(float);

        ~Car(); // Destructor
        //virtual ~Car();

        void FillFuel(float amount);
        void Accelerate();
        void Brake();
        void Addpassagers(int count);
        void Dashboard();
};