#include "Session.hpp"

#include <cstring>
#include <minwindef.h>

#include "Sequencies.hpp"

ACMTSpaceStart

using namespace ACMU;

TerminalSession::TerminalSession() noexcept
     : m_Input{ GetStdHandle(STD_INPUT_HANDLE) },
     m_Output{ GetStdHandle(STD_OUTPUT_HANDLE) }
{
    GetConsoleMode(m_Input, &m_OldInputMode);
    GetConsoleMode(m_Output, &m_OldOutputMode);

    const auto outMode = m_OldOutputMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(m_Output, outMode);

    const auto inMode = m_OldInputMode & ~ENABLE_ECHO_INPUT
        & ~ENABLE_LINE_INPUT & ~ENABLE_PROCESSED_INPUT
        | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

    SetConsoleMode(m_Input, inMode);

    Send(SQ::CSIStart + SL{ "?1049h"});
    Send(SQ::CSIStart + SL{ "?25l" });
    Send(SQ::CSIStart + SL{ "2J" } + SQ::CSIStart + SL{ "H" });
}

TerminalSession::~TerminalSession() noexcept
{
    Send(SQ::CSIStart + SL{ "?25h" });
    Send(SQ::CSIStart + SL{ "?1049l" });

    SetConsoleMode(m_Input, m_OldInputMode);
    SetConsoleMode(m_Output, m_OldOutputMode);
}

auto TerminalSession::Send(const char* const text) const noexcept -> DWORD 
{
    const auto size = std::strlen(text);

    auto sentDataSize = DWORD{};
    WriteConsoleA(m_Output, text, size, &sentDataSize, nullptr);

    return sentDataSize;
}

auto TerminalSession::Receive(INPUT_RECORD& record) const noexcept -> DWORD
{
    auto receivedDataSize = DWORD{};
    ReadConsoleInputW(m_Input, &record, 1, &receivedDataSize);

    return receivedDataSize;
}

ACMTSpaceEnd
