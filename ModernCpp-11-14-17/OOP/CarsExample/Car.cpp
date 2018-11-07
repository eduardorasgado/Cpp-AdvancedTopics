//
// Created by cheetos on 7/11/18.
//

#include "Car.h"

void Car::FillFuel(float amount)
{
    //
    this->fuel = amount;
}

void Car::Accelerate()
{
    //
    this->speed++;
    this->fuel -= 0.5f;
}

void Car::Brake()
{
    //
    this->speed = 0;
}

void Car::Addpassagers(int count)
{
    //
    this->passagers = count;
}

void Car::Dashboard()
{
    //
    std::cout << "FUEL: " << this->fuel << std::endl;
    std::cout << "SPEED: " << this->speed << std::endl;
    std::cout << "PASSAGERS: " << this->passagers << std::endl;
}
