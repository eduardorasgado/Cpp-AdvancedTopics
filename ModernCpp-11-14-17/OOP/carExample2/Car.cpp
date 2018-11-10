//
// Created by cheetos on 9/11/18.
//

#include "Car.h"

Car::Car() {
    count++;
    std::cout << "Car created." << std::endl;
    fuel = 0;
    speed = 0;
    passagers = 0;
}

Car::Car(float amount) {
    count++;
    this->fuel = amount;
    this->speed = 0;
    this->passagers = 0;
}

Car::Car(float amout, int passagers) {
    cout++;
    this->fuel = amount;
    this->speed = 0;
    this->passagers = passagers;
}

Car::~Car() {
    // Destructor
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
