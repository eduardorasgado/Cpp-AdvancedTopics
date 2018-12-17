#include <iostream>
#include "SQLite.h"

// C like approach
int main() {
    std::cout << "Welcome to SQLite integration!" << std::endl;

    try {
            Connection connection = Connection::Memory();
    } catch(Exception const & e)
    {
        // c_str: Returns a pointer to an array that contains a
        // null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
        std::cout << "Error: " << e.Message.c_str() << " => " << e.Result;
    }
    std::cout << "\nGood bye! [CONNECTION CLOSED]" << std::endl;
    return 0;
}