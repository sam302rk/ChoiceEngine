#pragma once

#include "Wrapper.h"
#include "Game.h"

namespace choice_engine
{
	class engine
	{
		wrapper wrapper_;
		game game_;
		
		public:
			engine(wrapper wrapper, game game);
			wrapper get_wrapper() const { return wrapper_; }
			game get_game() const { return game_; }
			
	};
}
