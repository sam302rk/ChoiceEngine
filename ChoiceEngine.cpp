#include "ChoiceEngine.h"

namespace choice_engine
{
	class engine_impl : public engine
	{
	private:
		implementation* impl_;
		char* chapter_;
		char* working_dir_;
		
	public:
		engine_impl(char* working_dir, char* initial_chapter, implementation* impl) : engine(working_dir, initial_chapter, impl)
		{ this->impl_ = impl; this->working_dir_ = working_dir; this->chapter_ = initial_chapter; }
		
		void send_user_input(int number) override
		{
			// TODO: Event Calling
		}
		
		void load_chapter(char* chapter) override
		{
			this->chapter_ = chapter;
			// TODO: Event Calling
		}

		implementation* get_implementation() override { return impl_; }
		char* get_chapter() override { return chapter_; }
		char* get_working_dir() override { return working_dir_; }
	};
}
