//
// Created by cheetos on 9/11/18.
//

#include "Car.h"

int Car::count = 0;

// amount, and passagers values
// delegated from base_constructor)
Car::Car(): Car(0, 0) {
    //
    std::cout << "#Car default initializer" << std::endl;
}

// amount named equals as variable delegated in
// base constructor
// in this case assigning amount to fuel attribute
Car::Car(float amount): Car(amount, 0) {
    //
    std::cout << "#Float car initializer" << std::endl;
}

// base_constructor)
Car::Car(float amount, int passagers) {
    std::cout << "#Car(float, int) initializer" << std::endl;
    count++;
    this->fuel = amount;
    this->speed = 0;
    this->passagers = passagers;
}

Car::~Car() {
    // Destructor
    std::cout << "Destructor executed" << std::endl;
}

void Car::FillFuel(float amount) {
    this->fuel = amount;
}

void Car::Accelerate() {
    this->speed++;
}

void Car::Brake() {
    this->speed = 0;
}

void Car::Dashboard() const {
    std::cout << "fuel: " << fuel << std::endl;
    std::cout << "speed: " << speed << std::endl;
    std::cout << "passagers: " << passagers << std::endl;
}
