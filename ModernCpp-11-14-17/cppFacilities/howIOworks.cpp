//
// Created by cheetos on 2/11/18.
//
#include <iostream>

int main()
{
    /*
     * CONSOLE I/O
     * input and output are:
     * std::basic_ostream and std::basic_istream
     *->
     * std::ostream and std::istream
     * ->
     * std::cout and std::cin
     * console out through << operator
     * keyboard input through >> operator
     * */
    std::cout << "Hello,\n " << 45 << "\n" << 8.2f << std::endl;

    // requesting data from user using cin and >>
    int age;
    std::cout << "Please insert your age: ";
    std::cin >> age;

    std::cout << "Your age is: " << age << std::endl;

    // requesting characters from user
    char buff[512];
    std::cout << "What is your name? ";
    // with no spaces
    std::cin >> buff;
    std::cout << "Your name is: " << buff << std::endl;
    // this is to empty the buffer in memory
    std::cin.ignore();

    // to read a string constains spaces
    char name[512];
    std::cout << "Your complete name please: ";
    // where to store, how many chars, delimiter
    std::cin.getline(name, 64, '\n');
    std::cout << "Your full name is: " << name << std::endl;

    return 0;
}
