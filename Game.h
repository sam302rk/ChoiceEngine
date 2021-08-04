#pragma once

namespace choice_engine
{
	class game
	{
		public:
			virtual ~game() = default;
			virtual void on_event(std::string event_name, std::string args...);
	};
}
