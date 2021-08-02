#pragma once
#include <string>

namespace choice_engine
{
	class dialog
	{
		public:
			dialog() = default;
		
			dialog(const std::string& param_npc, const std::string& param_text)
			{
				npc = param_npc;
				text = param_text;
			}
			std::string npc;
			std::string text;
	};

	enum class action : bool { continue_without_choice = false, choose = false, chapter = true };
	
	class element
	{
		dialog dialog_;
		action action_;
		std::string user_dialog_;

		public:
			element(const dialog& dialog, const action& action, const std::string& user_dialog)
			{
				dialog_ = dialog;
				action_ = action;
				user_dialog_ = user_dialog;
			}
	};

	class chapter : element
	{
		std::string chapter_name_;

		public:
			chapter(const dialog& dialog, const action& action, const std::string& user_dialog, const std::string& chapter_name) : element(dialog, action, user_dialog)
			{
				chapter_name_ = chapter_name;
			}
	};
}
