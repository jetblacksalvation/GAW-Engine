#ifndef GAW_ENGINE_WINDOW 
#define GAW_ENGINE_WINDOW 1
#include "GL/OOGL.hpp"

#include <unordered_map>
#include <string>
#include <vector>
namespace GAWEngine
{
	struct GAWWindow
	{
	public:
		uint64_t resolution[2];
		GL::Window window;


	};

	class WindowManager
	{
	private:

		std::unordered_map<std::string, GAWWindow> entries;
	public:
		WindowManager();
		/*
			On construction, reads the config wrapper for the defualt window size/name
		*/

		GAWWindow& operator[](std::string s) { return entries[s]; };

	};


	/*
		returns a copy of the current window
	*/


}
#endif