//
// Created by cheetos on 16/12/18.
//

#pragma once

// imported through conan package manager
#include "sqlite3.h"
// resource handler
#include "Handle.h"
#include <string>

// macros
#ifdef _DEBUG
#define VERIFY ASSERT
#define VERIFY_(result, expression) ASSERT(result == expression)
#else
#define VERIFY(expression) (expression)
#define VERIFY_(result, expression) (expression)
#endif

// Turning error into exceptions
struct Exception
{
    int Result = 0;
    std::string Message;
    explicit Exception(sqlite3 * const connection) :
    Result(sqlite3_extended_errcode(connection)),
    Message(sqlite3_errmsg(connection))
    {}
};

// to manipulate sqlite connections as handles
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
