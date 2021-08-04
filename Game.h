#pragma once

namespace choice_engine
{
	class game
	{
		public:
			virtual ~game() = default;

			/// <summary>
			/// Gets run every time a event gets called by the engine or by event nodes.
			/// </summary>
			/// <param name="event_name">Event name with following syntax: namespace::event_name</param>
			/// <param name="args">Event Arguments, Go to the wiki for more infos.</param>
			virtual void on_event(std::string* event_name, std::vector<std::string*> args);
	};
}
