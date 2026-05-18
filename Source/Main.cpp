#include <iostream>
#include <cstring>

#include "Terminal/Session.hpp"

auto main() -> std::int32_t 
{
	const auto session = ACMT::TerminalSession{};

	session.Send("Hello from full-screen console app");

	while (true)
	{
		auto record = INPUT_RECORD{};
        session.Receive(record);

		if (record.EventType == KEY_EVENT)
		{
			const auto& key = record.Event.KeyEvent;

			if (key.bKeyDown && key.wVirtualKeyCode == VK_ESCAPE)
			{
				break;
			}
		}
	}

	return EXIT_SUCCESS;
}
