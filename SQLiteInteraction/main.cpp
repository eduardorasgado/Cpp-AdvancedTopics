#include <iostream>
#include <vector>

#include "SQLite.h"

// C like approach
int main() {
    std::cout << "Welcome to SQLite integration!" << std::endl;

    try {
        // creating a database entirely in memory
        Connection connection = Connection::Memory();
        //Connection connection = Connection::WideMemory();

        // creating 2 physical databases, empties
        //Connection utf8("/home/cheetos/Developer/CProgramming/Cpp-AdvancedTopics/SQLiteInteraction/utf8database.db");
        //Connection utf16("/home/cheetos/Developer/CProgramming/Cpp-AdvancedTopics/SQLiteInteraction/utf16database.db");

        // inserting data into db
        //sqlite3_exec(utf8.GetAbi(), "create table Users (Name)", nullptr, nullptr, nullptr);
        //sqlite3_exec(utf16.GetAbi(), "create table Users (Name)", nullptr, nullptr, nullptr);

        // statement handler
        Statement statement;

        // in case not a utf8 encoding, statements first convert any encoding type
        // into utf8
        // preparing the query
        statement.Prepare(connection, "select ?1 union all select "
                                      "?2 union all select ?3 union all select ?4 union all select ?5"
                                      "union all select ?6", "Eduardo", 24, 16190278, "single", 70, "programmer");


        // showing the elements in the query
        for(Row const & row : statement)
        {
            std::cout << row.GetString(0) << "\n";
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