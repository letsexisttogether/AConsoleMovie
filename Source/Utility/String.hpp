#pragma once 

#include <algorithm>
#include <array>
#include <cstddef>
#include <type_traits>

#include "Core.hpp"

ACMUSpaceStart

template <std::size_t _Size>
class StringLiteral final
{
public:
    using Data = std::array<char, _Size>;

public:
    StringLiteral() = delete;

    consteval StringLiteral(const char (&string)[_Size]) noexcept
    {
        std::copy_n(string, _Size, m_Data.begin());
    }

    consteval StringLiteral(const Data& string) noexcept
    {
        std::copy(string.begin(), string.end(), m_Data.begin());
    }

    ~StringLiteral() = default;

    constexpr auto Size() const noexcept -> std::size_t
    {
        return _Size - 1;
    }

    constexpr operator const char* () const noexcept
    {
        return m_Data.data();
    }

private:
    Data m_Data{};
};

template <std::size_t _LeftSz, std::size_t _RightSz>
consteval auto Concatenate(const char (&left)[_LeftSz],
    const char (&right)[_RightSz]) noexcept -> 
    StringLiteral<_LeftSz + _RightSz - 1>
{
    auto result = std::array<char, _LeftSz + _RightSz - 1>{};

    for (auto i = 0uz; i < _LeftSz - 1; ++i)
    {
        result[i] = left[i];
    }

    for (auto i = 0uz; i < _RightSz; ++i)
    {
        result[_LeftSz - 1 + i] = right[i];
    }

    return { result };
}

ACMUSpaceEnd
