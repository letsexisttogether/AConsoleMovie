#pragma once

#include "Core.hpp"
#include "Utility/String.hpp"

#define ACMTSQSpace ACMT::SQ::
#define ACMTSQSpaceStart namespace ACMT::SQ {
#define ACMTSQSpaceEnd }

ACMTSQSpaceStart

inline constexpr auto Esc = ACMU::SL{ "\x1b" };
inline constexpr auto CSIStart = ACMU::SL{ "\x1b[" };

inline constexpr auto CursorHide = ACMU::SL{ "\x1b[?25l" };
inline constexpr auto CursorShow = ACMU::SL{ "\x1b[?25h" };

ACMTSQSpaceEnd
