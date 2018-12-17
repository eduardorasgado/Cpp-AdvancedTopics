//
// Created by cheetos on 16/12/18.
//
#pragma once

template <typename T>
struct HandleTraits
{
    // alias Type
    using Type = T;

    static Type Invalid() noexcept
    {
        return nullptr;
    }
};

template <typename Traits>
class Handle
{
        using Type = decltype(Traits::Invalid());
        Type m_value;

        void Close() noexcept
        {
            if(*this)
            {
                Traits::Close(m_value);
            }
        }

    public:
        // delete Copy constructor
        Handle(Handle const &) = delete;
        // delete asignation operator
        Handle & operator=(Handle const &) = delete;

        //The explicit function specifier controls unwanted implicit type conversions.
        explicit Handle(Type value = Traits::Invalid()) noexcept :
        m_value(value)
        { }

        // reset
        Handle(Handle && other) noexcept :
        m_value{other.Detach()}
        {}

        // move assignment operator
        Handle & operator=(Handle && other) noexcept
        {
            // check for auto assignment
            if(this != &other)
            {
                Reset(other.Detach());
            }
            return *this;
        }

        ~Handle() {
            Close();
        }
};