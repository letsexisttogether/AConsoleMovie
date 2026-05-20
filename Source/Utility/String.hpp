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

    consteval StringLiteral(const char (&rawString)[_Size]) noexcept
    {
        std::copy_n(rawString, _Size, m_Data.begin());
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

template <std::size_t _Size>
using SL = StringLiteral<_Size>;

template <std::size_t _LeftSz, std::size_t _RightSz>
consteval auto Concatenate(const StringLiteral<_LeftSz>& left,
    const StringLiteral<_RightSz>& right) noexcept
    -> StringLiteral<_LeftSz + _RightSz - 1>
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

    return result;
}

template <std::size_t _LeftSz, std::size_t _RightSz>
consteval auto operator + (const StringLiteral<_LeftSz>& left,
    const StringLiteral<_RightSz>& right) noexcept
    -> decltype(Concatenate(left, right))
{
    return Concatenate(left, right);
}

ACMUSpaceEnd
