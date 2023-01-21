#include "Display.h"

/*******Class:StWindow******/
StWindow::StWindow(const char* title, int x, int y, int w, int h, Uint32 flags)
	:Win(SDL_CreateWindow(title, x, y, w, h, flags)), WinID(SDL_GetWindowID(Win))
{
	if (Win == nullptr)
		StRecordLog(ST_LOG_TYPE_ERROR, "Failed to init window:" + std::to_string(WinID) + '-' + SDL_GetError() + '.');
	else
		StRecordLog(ST_LOG_TYPE_INFO, "Inited window:" + std::to_string(WinID) + '.');
}

StWindow::~StWindow() {
	SDL_DestroyWindow(Win);
	StRecordLog(ST_LOG_TYPE_INFO, "Destroy window:" + std::to_string(WinID) + '.');
}

/*******Class:StRenderer******/
StRenderer::StRenderer(SDL_Window& win, int index, Uint32 flags)
	:Ren(SDL_CreateRenderer(&win, index, flags)), WinID(SDL_GetWindowID(&win))
{
	if (Ren == nullptr)
		StRecordLog(ST_LOG_TYPE_ERROR, "Failed to init renderer:" + std::to_string(WinID) + '-'  +SDL_GetError() + '.');
	else
		StRecordLog(ST_LOG_TYPE_INFO, "Inited renderer:" + std::to_string(WinID) + '.');
}

StRenderer::	~StRenderer() {
	SDL_DestroyRenderer(Ren);
	StRecordLog(ST_LOG_TYPE_INFO, "Destroyed renderer:" + std::to_string(WinID) + '.');
}