#include <iostream>
#include "Car.h"

int main() {
    //
    Car myCar;

    myCar.FillFuel(60);
    myCar.Addpassagers(3);
    myCar.Accelerate();
    myCar.Accelerate();
    myCar.Accelerate();
    myCar.Accelerate();
    myCar.Dashboard();

    // initialized with some values
    Car sentra{6.7f};
    sentra.Addpassagers(1);
    sentra.Accelerate();
    sentra.Accelerate();
    sentra.Accelerate();
    sentra.Dashboard();

    return 0;
}