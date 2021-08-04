#pragma once

#include <string>
#include "Nodes.h"
#include "Wrapper.h"
#include "Game.h"

namespace choice_engine
{
	class engine
	{
		wrapper wrapper_;
		game game_;

	public:
		/// <summary>
		/// Start Engine using a custom wrapper.
		/// </summary>
		/// <param name="wrapper">Wrapper for platform specific tasks.</param>
		/// <param name="game">Event listener for the game.</param>
		engine(const wrapper& wrapper, const game& game)
		{
			wrapper_ = wrapper;
			game_ = game;
		}

		/// <returns>Returns the wrapper used for platform specific tasks.</returns>
		wrapper get_wrapper() const { return wrapper_; }

		/// <returns>Returns the game itself.</returns>
		game get_game() const { return game_; }
	};
}
