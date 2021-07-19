#include "ChoiceEngine.h"
#include <iostream>
using namespace std;

namespace choice_engine
{
	class engine_impl : public engine
	{
	private:
		implementation* impl_;
		string chapter_;
		string working_dir_;
		string current_dialog_element_;
		
	public:
		engine_impl(string working_dir, string initial_chapter, implementation* impl) : engine(working_dir, initial_chapter, impl)
		{
			this->impl_ = impl; this->working_dir_ = working_dir; this->chapter_ = initial_chapter; this->current_dialog_element_ = "_main_";
			get_implementation()->on_chapter_start_event(this->chapter_);
		}
		
		void send_user_input(int number) override
		{
			// TODO: Actually handle input
		}
		
		void load_chapter(const string chapter) override
		{
			get_implementation()->on_chapter_end_event(this->chapter_);
			get_implementation()->on_loading_start_event();
			this->chapter_ = chapter;
			// TODO: Actually loading chapter
			get_implementation()->on_loading_end_event();
			get_implementation()->on_chapter_start_event(this->chapter_);
		}

		implementation* get_implementation() override { return impl_; }
		string get_chapter() override { return chapter_; }
		string get_working_dir() override { return working_dir_; }

		object parse_file(string* content) override {
			// TODO
			return object();
		}
	};
}
