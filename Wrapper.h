#pragma once

#include <iostream>

namespace choice_engine
{
	class wrapper
	{
		public:
			wrapper() = default;
		
			/// <summary>
			/// Read file and return every line of file as array element.
			/// </summary>
			/// <param name="path">Path to the file.</param>
			/// <returns>Every line of file as array</returns>
			std::string* get_file(std::string path);
		 
			/// <summary>
			/// Does this file/directory exist?
			/// </summary>
			/// <param name="path">Path to the file/directory.</param>
			/// <returns>File/directory exists?</returns>
			bool does_path_exist(std::string path);
	};
}
