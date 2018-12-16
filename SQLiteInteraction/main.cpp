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

    // sqlite statement
    sqlite3_stmt * query = nullptr;
    result = sqlite3_prepare_v2(connection, "select 'Hello SQLite and Cpp'", -1, &query, nullptr);

    // in case it fails
    if(SQLITE_OK != result)
    {
        std::cout << sqlite3_errmsg(connection) << std::endl;
        sqlite3_close(connection);
        return result;
    }

    // for each row then we print the text in column
    // When sqlite3_step get the last element it returns SQLITE_DONE
    while(SQLITE_ROW == sqlite3_step(query))
    {
        std::cout << "THIS IS WHAT IS SAVED: " << std::endl;
        std::cout << sqlite3_column_text(query, 0);
    }

    //  finally
    sqlite3_finalize(query);
    sqlite3_close(connection);
    std::cout << "\nGood bye! [CONNECTION CLOSED]" << std::endl;

    return 0;
}