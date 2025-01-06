#ifndef GAW_ENGINE_WINDOW 
#define GAW_ENGINE_WINDOW 1

#include "GAW_RenderMain/GAW-Engine.h"
#include <unordered_map>
#include <string>
namespace GAWEngine
{
	class GAWWindow
	{
	public:
		uint64_t resolution[2];


	};
	static GAWWindow __GAW_DEFUALT_WINDOW;

	class WindowManager
	{
	private:
		WindowManager();
		/*
			On construction, load defaults and keep track of windows.
		*/

		std::unordered_map<std::string, GAWWindow> entries;
	public:
		GAWWindow operator[](std::string s) { return entries[s]; };

	};


	GAWWindow get_window_properties();
	/*
		returns a copy of the current window
	*/


}
#endif