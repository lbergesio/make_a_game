#ifndef TEXTURE_MGR_HEADER
#define TEXTURE_MGR_HEADER

#include "game.h"

class TextureManager{

public:
	static SDL_Texture* LoadTexture(const char* filename);
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst);

};

#endif
