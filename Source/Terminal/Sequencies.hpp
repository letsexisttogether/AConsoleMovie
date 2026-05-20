#pragma once

#include "Core.hpp"
#include "Utility/String.hpp"

#define ACMTSQSpace ACMT::SQ::
#define ACMTSQSpaceStart namespace ACMT::SQ {
#define ACMTSQSpaceEnd }

ACMTSQSpaceStart

inline constexpr auto CSIStart = ACMU::StringLiteral{ "\x1b[" };

ACMTSQSpaceEnd
