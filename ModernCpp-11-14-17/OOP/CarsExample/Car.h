#pragma once

#include <iostream>

class Car
{
    private:
        float fuel;
        float speed;
        int passagers;

    public:
        void FillFuel(float amount);
        void Accelerate();
        void Brake();
        void Addpassagers(int count);
        void Dashboard();
};