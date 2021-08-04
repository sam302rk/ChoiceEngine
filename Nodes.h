#pragma once
#include <string>
#include <vector>

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

	class dialog_choice
	{
		std::string* text_;
		std::string* node_;
		
	public:
		explicit dialog_choice(std::string* text, std::string* node)
		{
			text_ = text;
			node_ = node;
		}
	};
	
	class choice : dialog
	{
		std::vector<dialog_choice*> choices_;

	public:
		explicit choice(std::string* name, std::string* text, const std::vector<dialog_choice*> choices) : dialog(name, text)
		{
			choices_ = choices;
		}

		std::string* get_ini_header() override
		{
			return new std::string("[CHOICE]");
		}
		
		std::vector<dialog_choice*> get_choices() const
		{
			return choices_;
		}
	};

	class event_trigger : node
	{
		std::string* event_name_;
		
	public:
		explicit event_trigger(std::string* event_name) : node()
		{
			event_name_ = event_name;
		}

		std::string* get_ini_header() override
		{
			return new std::string("[TRIGGER_EVENT]");
		}

		std::string* get_event_name() const
		{
			return event_name_;
		}
	};
}
