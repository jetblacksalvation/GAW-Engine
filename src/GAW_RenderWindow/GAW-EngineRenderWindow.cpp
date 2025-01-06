#include "GAW_RenderWindow/GAW-EngineRenderWindow.h"


namespace GAWEngine
{
	GAWWindow get_window_properties() {
		__GAW_DEFUALT_WINDOW.resolution = { 800,800 };
		return __GAW_DEFUALT_WINDOW;

	};


}