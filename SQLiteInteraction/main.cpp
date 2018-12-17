#include <iostream>
#include "SQLite.h"

// C like approach
int main() {
    std::cout << "Welcome to SQLite integration!" << std::endl;

    // connection object, database within the app
    //sqlite3 *connection = nullptr;
    ConnectionHandle connection;

    try {
        // using seudo file name to create an in memory database. Database is initialized
        if (SQLITE_OK != sqlite3_open(":memory:", connection.Set()))
        {
            throw Exception(connection.Get());
        } else {
            std::cout << "Everything were like spected [CONECTION DONE]" << std::endl;
        }
    } catch(Exception const & e)
    {
        // c_str: Returns a pointer to an array that contains a
        // null-terminated sequence of characters (i.e., a C-string) representing the current value of the string object.
        std::cout << "Error: " << e.Message.c_str() << " => " << e.Result;
    }
    std::cout << "\nGood bye! [CONNECTION CLOSED]" << std::endl;
    return 0;
}