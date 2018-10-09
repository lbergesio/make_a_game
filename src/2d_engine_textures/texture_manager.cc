#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture,
							SDL_Renderer* rend){
	SDL_Surface* tmpSurface = IMG_Load(texture);
	if(!tmpSurface){
		std::cout << "Texture player not found!" << std::endl;
		exit(1);
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tex;
}
