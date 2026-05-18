#pragma once 

#include <windows.h>

#include "Core.hpp"

ACMTSpaceStart

class TerminalSession final
{
public:
	TerminalSession() noexcept;

	TerminalSession(const TerminalSession&) = delete;
    TerminalSession(TerminalSession&&) = delete;

	~TerminalSession() noexcept;

    /**
    * @brief Sends the data to the std-input handler
    *
    * @param text - raw data to send
    *
    * @returns Size of sent data in bytes
    */
	auto Send(const char* const text) const noexcept -> DWORD;
    /**
    * @brief Receives the data from the std-input handler
    *
    * @param record - object to put received data in
    *
    * @returns Size of received data in bytes
    */
    auto Receive(INPUT_RECORD& record) const noexcept -> DWORD;

	auto operator = (const TerminalSession&) -> TerminalSession& = delete;
	auto operator = (TerminalSession&&) -> TerminalSession& = delete;

private:
	HANDLE m_Input{};
	HANDLE m_Output{};
	DWORD m_OldInputMode{};
	DWORD m_OldOutputMode{};
};

ACMTSpaceEnd
