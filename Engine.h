#pragma once

#include <string>
#include "Wrapper.h"
#include "Game.h"

namespace choice_engine
{
	class engine
	{
		wrapper wrapper_;
		game game_;
		std::string current_dialog_ = "chapter0";

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

		std::string get_current_dialog() const { return current_dialog_; }

		/// <summary>
		/// Select Choice
		/// </summary>
		/// <param name="choice">The selected choice</param>
		void add_choice(const int& choice)
		{
			current_dialog_.append("/choice");
			current_dialog_.append(std::to_string(choice));
		}

		/// <summary>
		/// Load new chapter.
		/// </summary>
		/// <param name="chapter">The Chapter number starting at 0.</param>
		void set_chapter(const int chapter)
		{
			current_dialog_ = "chapter" + std::to_string(chapter);
		}

		/// <summary>
		/// Overrides the current dialog path.
		/// </summary>
		/// <param name="path">New path for overriding.</param>
		void set_choice(const std::string& path)
		{
			current_dialog_ = path;
		}
		
	};
}