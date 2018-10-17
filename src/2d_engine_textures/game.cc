#include "game.h"
#include "map.h"
#include "texture_manager.h"
#include "ecs/components.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());

Game::Game(){}

void Game::init(const char* title, int xpos, int ypos, int width, int height,
        					bool fullscreen){

	int flags = (fullscreen ? SDL_WINDOW_FULLSCREEN : 0);

	if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
		std::cout << "Subsystems initialized!" << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height,
									flags);
		if(window)
			std::cout << "Window created!" << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);
		if(renderer){
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}else{
		isRunning = false;
	}

	map = new Map();

	player.addComponent<PositionComponent>();
	player.addComponent<SpriteComponent>("src/2d_engine_textures/assets/player32.png");
}

void Game::handleEvents(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type){
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}

}

void Game::update(){
	manager.refresh();
	manager.update();

	if(player.getComponent<PositionComponent>().x() > 100){
		player.getComponent<SpriteComponent>().setTex("src/2d_engine_textures/assets/player32_red.png");
	}
}

void Game::render(){
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
