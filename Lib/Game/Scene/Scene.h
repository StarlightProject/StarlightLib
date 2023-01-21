#ifndef _SCENE_H_
#define _SCENE_H_

#include "../../Display/Display.h"

class StScene {
public:
	StScene();
	~StScene();

private:
	friend class StWindow;
};

#endif
