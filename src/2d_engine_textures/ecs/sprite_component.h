#ifndef SPRITE_COMPONENT_HEADER
#define SPRITE_COMPONENT_HEADER

#include "components.h"
#include <SDL2/SDL.h>

class SpriteComponent : public Component
{
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect;
	SDL_Rect dstRect;

public:
	SpriteComponent() = default;

	SpriteComponent(const char* path){
		setTex(path);
	}

	void setTex(const char* path){
		texture = TextureManager::LoadTexture(path);
	}

	void init() override{
		position = &entity->getComponent<PositionComponent>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		dstRect.w = dstRect.h = 64;
	}

	void update() override{
		dstRect.x = position->x();
		dstRect.y = position->y();;
	}

	void draw() override{
		TextureManager::Draw(texture, srcRect, dstRect);
	}
};

#endif
