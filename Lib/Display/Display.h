#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <SDL2/SDL.h>

#include "../Tools/Tools.h"

class StWindow {
public:
	//Create a window
	StWindow(const char* title, int x, int y, int w, int h, Uint32 flags);
	//Destroy a window
	~StWindow();

public:
	const int WinID;
	//A window object
	SDL_Window* Win;

private:
};

class StRenderer {
public:
	//Create a Renderer
	StRenderer(SDL_Window& win, int index, Uint32 flags);
	//Destroy a Renderer
	~StRenderer();
public:
	//The window points to the renderer
	const int WinID;
	//A renderer object
	SDL_Renderer* Ren;
};

#endif