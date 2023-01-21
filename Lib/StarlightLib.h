#ifndef _STARLIGHTLIB_H_
#define _STARLIGHTLIB_H_

#define ST_LIB_RELEASE_TYPE		"DEV"
#define ST_LIB_RELEASE_VERSION	"0.0.6"

#include "Tools/Tools.h"
#include "Display/Display.h"
#include "Game/Texture/Texture.h"
#include "Game/Scene/Scene.h"
#include "Game/Elements/Elements.h"

#undef main

class StGame {
public:
	StGame();
	~StGame();
};

#endif