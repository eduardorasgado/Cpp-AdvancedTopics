#include <iostream>

//#include "sqlite-amalgamation/sqlite3.h"

// imported through conan package manager
#include "sqlite3.h"

int main() {
    std::cout << "Welcome to SQLite integration!" << std::endl;

    // connection object, database within the app
    sqlite3 *connection = nullptr;

    // using in memory database. Database is initialized
    auto result = sqlite3_open(":memory:", &connection);

    if(SQLITE_OK != result)
    {
        // if there is no allocate sufficient memory it will not be possible to
        // create the connection, then the error
        std::cout << "Error: " << sqlite3_errmsg(connection) << std::endl;
        // destructs the connection by setting a nullptr
        sqlite3_close(connection);
        return result;
    } else
    {
        std::cout << "Everything were like spected [CONECTION DONE]" << std::endl;
    }

    return 0;
}