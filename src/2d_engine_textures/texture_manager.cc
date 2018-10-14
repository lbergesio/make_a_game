#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture){
	SDL_Surface* tmpSurface = IMG_Load(texture);
	if(!tmpSurface){
		std::cout << "Texture not found!" << std::endl;
		exit(1);
	}
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,
								tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return tex;
}
	
void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst){
	SDL_RenderCopy(Game::renderer, tex, &src, &dst);
}
