#pragma once
namespace choice_engine
{	
	class implementation
	{
		public:
			// Events
			virtual void on_new_dialog_element_event(string author, string text);	// A new DialogElement got received.
			virtual void on_voice_line_play_event(string voice_line);			// A voice-line should be played based on Config-Data.
			virtual void on_user_input_required_event(string choices[]);			// Received some new choices for the user to choose from.
			virtual void on_chapter_start_event(string chapter);					// A new Chapter started.
			virtual void on_chapter_end_event(string chapter);					// This chapter is complete. This event should be used for achievements based on chapter.
			virtual void on_loading_start_event();								// Show a loading screen instead of game
			virtual void on_loading_end_event();								// Loading screen can be hidden, at least the engine is done loading
			
			// File Managment
			virtual string load_file(string file_name);							// Load file
			virtual void override_file(string file_name, string content);			// Override file (File's content should become content)
			virtual void append_to_file(string file_name, string content);		// Append to file (File's content should be old content + new content)
			
	};

	class engine
	{
		public:
			engine(string working_dir, string initial_chapter, implementation* impl) {}
			virtual void send_user_input(int number);								// Send User Input from OnUserInputRequiredEvent to Engine.
			virtual void load_chapter(string chapter);								// Loads a chapter manually.
			virtual implementation* get_implementation();
			virtual string get_chapter();
			virtual string get_working_dir();
	};
}
