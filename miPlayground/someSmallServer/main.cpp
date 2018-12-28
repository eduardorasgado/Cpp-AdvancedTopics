#include <iostream>
#include <memory>
#include <cstring>
// including sqlite ORM
#include "sqlite_orm/sqlite_orm.h"

struct Employee {
    int id;
    std::string name;
    int age;
    std::string address;
    double salary;
};

struct DetailedEmployee : public Employee {
    std::string birthDate;
};

using namespace sqlite_orm;

int main() {
    std::cout << "[SHOWING SOME DATA]" << std::endl;

    return 0;
}