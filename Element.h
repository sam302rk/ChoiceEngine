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
	
	class element
	{
		dialog* dialog_;
		std::string* action_;
		std::string* user_dialog_;

		public:
			element(dialog* dialog, std::string* action, std::string* user_dialog)
			{
				dialog_ = dialog;
				action_ = action;
				user_dialog_ = user_dialog;
			}
	};

	class chapter : element
	{
		std::string* chapter_name_;

		public:
			chapter(dialog* dialog, std::string* action, std::string* user_dialog, std::string* chapter_name) : element(dialog, action, user_dialog)
			{
				chapter_name_ = chapter_name;
			}
	};
}
