//
// Created by cheetos on 16/12/18.
//

#pragma once
#include <string>
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

// Modeling connections
class Connection
{
    private:
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

        ConnectionHandle m_handle;

        // function and a character
        template <typename F, typename C>
        void InternalOpen(F open, C const * const filename)
        {
            Connection temp;

            if(SQLITE_OK != open(filename, temp.m_handle.Set()))
            {
                // reporting error
                temp.ThrowLastError();
            }
            // In handle header
            Swap(m_handle, temp.m_handle);
        }
    public:

        Connection() noexcept = default;

        template <typename C>
        explicit Connection(C const * const filename)
        {
            Open(filename);
        }

        static Connection Memory()
        {
            // to create in memory connections
            return Connection(":memory:");
        }

        static Connection WideMemory()
        {
            // L encoding variation
            return Connection(L":memory:");
        }

        explicit operator bool() const noexcept
        {
            return static_cast<bool>(m_handle);
        }

        sqlite3 * GetAbi() const noexcept
        {
            return m_handle.Get();
        }

        // it was a __declspec
        void ThrowLastError() const
        {
            // Application binary interface
            throw Exception(GetAbi());
        }

        // Open overloads
        void Open(char const * const filename)
        {
            InternalOpen(sqlite3_open, filename);
        }

        // wchar_t stands for Wide character
        void Open(wchar_t const * const filename)
        {
            InternalOpen(sqlite3_open16, filename);
        }


};