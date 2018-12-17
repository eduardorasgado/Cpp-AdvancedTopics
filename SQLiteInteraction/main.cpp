#include <iostream>
// imported through conan package manager
#include "sqlite3.h"
// resource handler
#include "Handle.h"

// macros
#ifdef _DEBUG
#define VERIFY ASSERT
#define VERIFY_(result, expression) ASSERT(result == expression)
#else
#define VERIFY(expression) (expression)
#define VERIFY_(result, expression) (expression)
#endif

struct ConnectionHandleTraits : HandleTraits<sqlite3 *>
{
    static void Close(Type value) noexcept
    {
        // call the macro instead
        VERIFY_(SQLITE_OK, sqlite3_close(value));
    }
};

// alias for convenience
using ConnectionHandle = Handle<ConnectionHandleTraits>;

// C like approach
int main() {
    std::cout << "Welcome to SQLite integration!" << std::endl;

    // connection object, database within the app
    //sqlite3 *connection = nullptr;
    ConnectionHandle connection;

    // using in memory database. Database is initialized
    auto result = sqlite3_open(":memory:", connection.Set());

    if (SQLITE_OK != result) {
        // if there is no allocate sufficient memory it will not be possible to
        // create the connection, then the error
        std::cout << "Error: " << sqlite3_errmsg(connection.Get()) << std::endl;
        return result;
    } else {
        std::cout << "Everything were like spected [CONECTION DONE]" << std::endl;
    }

    std::cout << "\nGood bye! [CONNECTION CLOSED]" << std::endl;

    return 0;
}