//
// Created by cheetos on 7/11/18.
//

#include "Car.h"


// static member variables initialization
// it should not have static keyword
// just in declaration inside the class
// a static member variable  should not be
// initialized inside the class
int Car::count = 0;

Car::Car()
{
    count++;
}

Car::Car(float amount)
{
    this->fuel= amount;
    count++;
}

Car::~Car()
{
    std::cout << "Car destructed." << std::endl;
}

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

// const means that this member function cannot change
// any value within the class
void Car::Dashboard() const
{
    //
    std::cout << "FUEL: " << this->fuel << std::endl;
    std::cout << "SPEED: " << this->speed << std::endl;
    std::cout << "PASSAGERS: " << this->passagers << std::endl;
}

int Car::getCount()
{
    return count;
}