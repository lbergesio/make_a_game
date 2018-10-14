#ifndef GAME_OBJECT_HEADER
#define GAME_OBJECT_HEADER


#include "game_object.h"
#include "texture_manager.h"

GameObject::GameObject(const char* textureSheet, int x, int y){
	objTexture = TextureManager::LoadTexture(textureSheet);
	if(!objTexture){
		std::cout << "Could not load object texture: %s!!" << textureSheet << std::endl; 
		exit(1);
	}

	xpos = x;
	ypos = y;
}

void GameObject::Update(){
	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	dstRect.h = srcRect.h * 2;
	dstRect.w = srcRect.w * 2;
	dstRect.x = xpos;
	dstRect.y = ypos;
}

void GameObject::Render(){
	if(SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &dstRect))
		std::cout << "Game object not rendered!: %s" << SDL_GetError() << std::endl; 

}

#endif
