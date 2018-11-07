#include <iostream>
#include "Car.h"

// STRUCTS
// structs attributes are public by default
// are usually used to create small representations
// of simple objects
struct Point
{
    int x;
    int y;
};

void DrawLine(int, int, int, int);
void DrawLine(Point, Point);

int main() {
    // classes
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

    // structs
    Point p1{4, 8};
    Point p2{10, 20};

    DrawLine(p1, p2);
    return 0;
}

void DrawLine(int x1, int y1, int x2, int y2)
{
    //
    std::cout << x1 << std::endl;
    std::cout << y1 << std::endl;
    std::cout << x2 << std::endl;
    std::cout << y2 << std::endl;
}

void DrawLine(Point start, Point end)
{
    //
    std::cout << "x(start): " << start.x << std::endl;
    std::cout << "x(end): " << end.x << std::endl;
}