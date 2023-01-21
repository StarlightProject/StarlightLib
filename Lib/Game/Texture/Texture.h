#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <SDL2/SDL_image.h>
#include <string>

#include "../../Tools/Tools.h"

class StTexture {
public:
	StTexture(const std::string file, SDL_Renderer& ren,
		unsigned int FrameNumW/*The number of frames on X axis*/, unsigned int FrameNumH/*The number of frames on Y axis*/,
		unsigned int wzoom/*Width zoom multiple*/, unsigned int hzoom/*Height zoom multiple*/);
	~StTexture();

	//apply the texture
	void StApplyTexture(SDL_Renderer& ren, unsigned int framenum);
public:
	//A texture object
	const std::string TexFile;
	//The number of texture's frame
	const unsigned int FrameNumW;
	const unsigned int FrameNumH;
	//A texture object
	SDL_Texture* Tex;
	//The position of the texture
	SDL_Rect Pos;
	//The frames of the texture
	SDL_Rect* Frame;
};

#endif