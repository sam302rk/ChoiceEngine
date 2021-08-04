#pragma once
#include <string>

namespace choice_engine
{
	class node
	{
	public:
		virtual ~node() = default;
		
		virtual std::string* get_ini_header()
		{
			return new std::string("[NODE]");
		}
	};

	class chapter : node
	{
		std::string* title_;
		
	public:
		explicit chapter(std::string* title): node()
		{
			title_ = title;
		}
		
		std::string* get_ini_header() override
		{
			return new std::string("[CHAPTER]");
		}
		
		std::string* get_title() const
		{
			return title_;
		}
	};

	class dialog : node
	{
		std::string* name_;
		std::string* text_;

	public:
		dialog(std::string* name, std::string* text) : node()
		{
			name_ = name;
			text_ = text;
		}

		std::string* get_ini_header() override
		{
			return new std::string("[DIALOG]");
		}

		std::string* get_name() const
		{
			return name_;
		}
		
		std::string* get_text() const
		{
			return text_;
		}
	};

	class player_dialog : dialog
	{
	public:
		explicit player_dialog(std::string* text) : dialog(new std::string("Player"), text)
		{
		}

		std::string* get_ini_header() override
		{
			return new std::string("[PLAYER_DIALOG]");
		}
	};
}
