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

// ROW READER FOR STATEMENTS
template <typename T>
struct Reader
{
    // to be able to read rows by columns in the controller or main
    int GetInt(int const column = 0) const noexcept
    {
        // doing a static cast because GetAbi is a const method
        return sqlite3_column_int(static_cast<T const *>(this)->GetAbi(), column);
    }
    char const * GetString(int const column = 0) const noexcept
    {
        return reinterpret_cast<char const *>(sqlite3_column_text(
                static_cast<T const *>(this)->GetAbi(), column
                ));
    }

    // string overloaded for no regular string
    wchar_t const * GetWideString(int const column = 0) const noexcept
    {
        return static_cast<wchar_t const *>(sqlite3_column_text16(
                static_cast<T const *>(this)->GetAbi(), column
                ));
    }

    int GetStringLength(int const column = 0) const noexcept
    {
        return sqlite3_column_bytes(static_cast<T const *>(this)->GetAbi(), column);
    }

    int GetWideStringLength(int const column = 0) const noexcept
    {
        return sqlite3_column_bytes16(static_cast<T const *>(this)->GetAbi(), column) / sizeof(wchar_t);
    }
};

// SQLITE STATEMENTS HANDLERS

class Statement : public Reader<Statement>
{
    private:
        struct StatementHandleTraits : HandleTraits<sqlite3_stmt *>
        {
            static void Close(Type value) noexcept
            {
                VERIFY_(SQLITE_OK, sqlite3_finalize(value));
            }
        };

        // statement alias
        using StatementHandle = Handle<StatementHandleTraits>;

        StatementHandle m_handle;

        template <typename F, typename C>
        void InternalPrepare(Connection const & connection, F prepare, C const * const text)
        {
            assert(connection);
            if(SQLITE_OK != prepare(connection.GetAbi(), text, -1, m_handle.Set(), nullptr))
            {
                connection.ThrowLastError();
            }
        }

    public:
        Statement() noexcept = default;

        explicit operator bool() const noexcept
        {
            return static_cast<bool>(m_handle);
        }

        // abi
        sqlite3_stmt * GetAbi() const noexcept
        {
            return m_handle.Get();
        }

        void ThrowLastError() const
        {
            throw Exception (sqlite3_db_handle(GetAbi()));
        }

        // prepare overloading for different encodings
        void Prepare(Connection const & connection, char const * const text)
        {
            // prepare_V2 much more stable with error recording
            InternalPrepare(connection, sqlite3_prepare_v2, text);
        }

        void Prepare(Connection const & connection, wchar_t const * const text)
        {
            InternalPrepare(connection, sqlite3_prepare16_v2, text);
        }

        bool Step() const
        {
            // statement executions
            int const result = sqlite3_step(GetAbi());
            // it is still executing
            if(result == SQLITE_ROW) return true;
            // it says it has been executed successfully
            if(result == SQLITE_DONE) return false;

            // in case no response is received
            ThrowLastError();
        }

        void Execute() const {
            VERIFY(!Step());
        }
};