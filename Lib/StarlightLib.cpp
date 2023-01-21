#include "StarlightLib.h"

/*******Class:StGame*******/
StGame::StGame()
{
	std::string ver = ST_LIB_RELEASE_VERSION;
	std::string type = ST_LIB_RELEASE_TYPE;
	StInitLog();
	StRecordLog(ST_LOG_TYPE_OTHER, " ========================= StarlightLib - Verison " + ver + " - Type " + type + " ========================= ");
	if (SDL_Init(SDL_INIT_EVERYTHING))
		StRecordLog(ST_LOG_TYPE_FAILED, "Failed to init sdl!");
	else
		StRecordLog(ST_LOG_TYPE_INFO, "Inited sdl.");
	if(IMG_Init(SDL_INIT_EVERYTHING))
		StRecordLog(ST_LOG_TYPE_FAILED, "Failed to init sdl_image!");
	else
		StRecordLog(ST_LOG_TYPE_INFO, "Inited sdl_image.");
	StRecordLog(ST_LOG_TYPE_INFO, "Init StGame complete.");
}

StGame::~StGame() {
	SDL_Quit();
	StRecordLog(ST_LOG_TYPE_INFO, "Sdl exited.");
	StRecordLog(ST_LOG_TYPE_INFO, "StGame exited.");
	StDestoryLog();
}