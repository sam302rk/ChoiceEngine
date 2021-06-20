#pragma once
#include <string>
using namespace std;

namespace choice_engine
{	
	class object {};

	class chapter : public object {
	private:
		std::string name_;
		string subtitle_;
		bool visible_;

	public:
		chapter(string name, string subtitle, bool visible) {
			this->name_ = name;
			this->subtitle_ = subtitle;
			this->visible_ = visible;
		};

		string get_name() const { return name_; }
		string get_subtitle() const { return subtitle_; }
		bool is_visible() const { return visible_; }
	};

	class dialog_element : public object {
	private:
		string author_;
		string text_;
		string options_[];

	public:
		dialog_element(string author, string text, string options[]) {
			this->author_ = author;
			this->text_ = text;
			*this->options_ = *options;
		}

		string get_author() const { return author_;  }
		string get_text() const { return text_; }
		const string* get_options() const { return options_; }
	};

	class implementation
	{
		public:
			// Events
			virtual void on_new_dialog_element_event(string author, string text);	// A new DialogElement got received.
			virtual void on_voice_line_play_event(string voice_line);				// A voice-line should be played based on Config-Data.
			virtual void on_user_input_required_event(string choices[]);			// Received some new choices for the user to choose from.
			virtual void on_chapter_start_event(string chapter);					// A new chapter started.
			virtual void on_chapter_end_event(string chapter);						// The current chapter is complete. This event should be used for achievements based on chapter.
			virtual void on_loading_start_event();									// Show a loading screen instead of game.
			virtual void on_loading_end_event();									// Loading screen can be hidden, at least the engine is done loading.
			
			// File Management
			virtual string* load_file(string file_name);							// Load file
			virtual void override_file(string file_name, string* content);			// Override file (File's content should become content)
			virtual void append_to_file(string file_name, string* content);			// Append to file (File's content should be old content + new content)
	};

	class engine
	{
		public:
			engine(string working_dir, string initial_chapter, implementation* impl) {}
			virtual void send_user_input(int number);								// Send User Input from OnUserInputRequiredEvent to Engine.
			virtual void load_chapter(string chapter);								// Loads a chapter manually.
			virtual implementation* get_implementation();							// Gets instance of engine implementation
			virtual string get_chapter();											// Gets current chapter
			virtual string get_working_dir();										// Gets working directory
			virtual object parse_file(string* textToParse);							// Parse *.ce file to CE objects
	};
}
