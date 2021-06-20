#pragma once
namespace choice_engine
{	
	class implementation
	{
		public:
			// Events
			void on_new_dialog_element_event(char* author, char* text);	// A new DialogElement got received.
			void on_voice_line_play_event(char* voice_line);			// A voice-line should be played based on Config-Data.
			void on_user_input_required_event(char* choices[]);			// Received some new choices for the user to choose from.
			void on_chapter_start_event(char* chapter);					// A new Chapter started.
			void on_chapter_end_event(char* chapter);					// This chapter is complete. This event should be used for achievements based on chapter.
			void on_loading_start_event();								// Show a loading screen instead of game
			void on_loading_end_event();								// Loading screen can be hidden, at least the engine is done loading
			
			// File Managment
			char* load_file(char* file_name);							// Load file
			void override_file(char* file_name, char* content);			// Override file (File's content should become content)
			void append_to_file(char* file_name, char* content);		// Append to file (File's content should be old content + new content)
			
	};

	class engine
	{
		public:
			engine(char* working_dir, char* initial_chapter, implementation* impl) {}
			virtual void send_user_input(int number);								// Send User Input from OnUserInputRequiredEvent to Engine.
			virtual void load_chapter(char* chapter);								// Loads a chapter manually.
			virtual implementation* get_implementation();
			virtual char* get_chapter();
			virtual char* get_working_dir();
	};
}
