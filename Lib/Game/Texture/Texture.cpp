#include "Texture.h"

/*******Class:StTexture******/
StTexture::StTexture(const std::string file, SDL_Renderer& ren,
	unsigned int framenumw, unsigned int framenumh, unsigned int wzoom, unsigned int hzoom)
	:TexFile(file), Tex(IMG_LoadTexture(&ren, file.c_str())), Pos(), Frame(), FrameNumW(framenumw), FrameNumH(framenumh)
{
	if (Tex == nullptr)
		StRecordLog(ST_LOG_TYPE_ERROR, "Failed to load image:" + TexFile + '-' + IMG_GetError() + '.');
	else
		StRecordLog(ST_LOG_TYPE_INFO, "Loaded image:" + TexFile + '.');
	Pos.x = 0;
	Pos.y = 0;
	int imgw, imgh;
	if (SDL_QueryTexture(Tex, NULL, NULL, &imgw, &imgh))
		StRecordLog(ST_LOG_TYPE_ERROR, "Failed to query texture information:" + TexFile + '-' + SDL_GetError() + '.');
	Frame = new SDL_Rect[FrameNumW * FrameNumH];
	for (unsigned int i = 0; i < FrameNumW; i++) {
		for (unsigned int j = 0; j < FrameNumH; j++) {
			Frame[i + j].x = i * (imgw / FrameNumW);
			Frame[i + j].y = j * (imgh / FrameNumH);
			Frame[i + j].w = imgw / FrameNumW;
			Frame[i + j].h = imgh / FrameNumH;
		}
	}
	Pos.w = (imgw / FrameNumW) * wzoom;
	Pos.h = (imgh / FrameNumH) * hzoom;
}

StTexture::~StTexture() {
	delete[]Frame;
	StRecordLog(ST_LOG_TYPE_INFO, "Destroyed frame of:" + TexFile + '.');
	SDL_DestroyTexture(Tex);
	StRecordLog(ST_LOG_TYPE_INFO, "Destroyed texture:" + TexFile + '.');
}

void StTexture::StApplyTexture(SDL_Renderer& ren, unsigned int framenum) {
	if (framenum <= 0 || framenum > FrameNumW * FrameNumH) {
		StRecordLog(ST_LOG_TYPE_ERROR, "Invalid parameter:framenum=" + std::to_string(framenum) + '.');
		return;
	}
	if (SDL_RenderCopy(&ren, Tex, &Frame[framenum - 1], &Pos))
		StRecordLog(ST_LOG_TYPE_ERROR, "Failed to apply texture:" + TexFile + '-' + SDL_GetError() + '.');
	else
		StRecordLog(ST_LOG_TYPE_INFO, "Applied texture:" + TexFile + " - position (" + std::to_string(Pos.x) + ',' + std::to_string(Pos.y) + ").");
}