//
// Created by cheetos on 27/12/18.
//

#pragma once

#include <iostream>

struct User {
    int id;
    std::string first_name;
    std::string last_name;
    int age;
    std::string address;
    double salary;
    std::shared_ptr<std::string> imageUrl;
    int typeId;
};

struct UserType {
    int id;
    std::string name;
};
