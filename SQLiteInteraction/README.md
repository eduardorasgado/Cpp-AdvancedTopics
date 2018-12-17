# SQLite and Modern C++ Integration

This project is a handler for C++ SQLite3 API. It is intended to create a simple way to interact with database.

## Compile the project
Linux based compilation:

To compile the project install [Conan C++ Package manager](http://conan.io) and install sqlite3 using conan in your system, you can find it in conan center,
then just run:
```console
foo@bar :~$ mkdir build && cd build
foo@bar :~$ conan install ..
foo@bar :~$ cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
foo@bar :~$ cmake --build .
``` 

## How to use
sqlite-amalgamation folder is standalone, and it is not used in the project(because we installed it using Conan).\
Handle.h and SQLite.h are the celebrities here.\
Once sqlite is installed in your project by using conan, you can interact with sqlite in a easy way.

### Include in your project

```C++
#include "SQLite.h"
```

### Creating a connection

```C++
try {
    // creating a database entirely in memory
    Connection connection = Connection::Memory();
    //or if you're using it to store wide characters 
    Connection connection = Connection::WideMemory();
}
```

### Creating databases and inserting data

```C++
/// instead of in memory
// creating 2 physical databases, empties
Connection utf8("/home/cheetos/Developer/CProgramming/Cpp-AdvancedTopics/SQLiteInteraction/utf8database.db");
Connection utf16("/home/cheetos/Developer/CProgramming/Cpp-AdvancedTopics/SQLiteInteraction/utf16database.db");
```

### Executing a query and binding data
```C++
// statement handler
Statement statement;

// in case not a utf8 encoding, statements first convert any encoding type
// into utf8
// preparing the query
statement.Prepare(connection, "select ?1 union all select "
                              "?2 union all select ?3 union all select ?4 union all select ?5"
                              "union all select ?6");

// BINDING regular encodings
std::vector<std::string> data{"Hello", " ", "SQLite3 and C++"};

// if bindingAll is called and Bind too then BindAll should be called first
// automatic binding
statement.BindAll("hello", std::string("Your"), std::string("Name"));

// common bindings
statement.Bind(4, data[0]);
// binding a r-value is possible
statement.Bind(5, std::string("everybody over"));
statement.Bind(6, data[2]);
```

### Read the rows in your statement

```C++
// calling the Row iterator classes
for(Row const & row : statement)
{
    // simple loop for reading rows
    // using the reader
    std::cout << row.GetString(0) << "\n";
}
```