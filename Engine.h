#pragma once

#include <string>
#include "Element.h"
#include "Wrapper.h"
#include "Game.h"

namespace choice_engine
{
	class engine
	{
		wrapper wrapper_;
		game game_;
		std::string current_dialog_ = "chapter0";
		element* current_dialog_element_;

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
			current_dialog_element_ = load_current_element();
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

		/// <summary>
		/// Checks if the path includes directories. This is useful because a chapter element can't have a "continue_to_next_chapter" action to prevent bad pratice.
		/// </summary>
		/// <returns>Is the current dialog the chapter root?</returns>
		bool current_dialog_is_chapter() const
		{
			return get_current_dialog().find('/');
		}

		/// <summary>
		/// Loads current dialog element.
		/// </summary>
		element* load_current_element() const
		{
			std::string* dialog_file = get_wrapper().read_file(get_current_dialog() + "/dialog");
			std::string* action_file = get_wrapper().read_file(get_current_dialog() + "/action");
			std::string* user_dialog = get_wrapper().read_file(get_current_dialog() + "/user_dialog");
			return new element(new dialog(dialog_file[0], dialog_file[1]), action_file, user_dialog);
		}
		
	};
}
