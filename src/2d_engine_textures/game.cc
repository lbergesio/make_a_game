#include "game.h"
#include "map.h"
#include "game_object.h"
#include "texture_manager.h"

GameObject* player;
GameObject* enemy;
Map* map;

SDL_Renderer* Game::renderer = nullptr;

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

	const char* filename = "src/2d_engine_textures/assets/player32.png";
	player = new GameObject(filename, 0, 0);
	const char* filename2 = "src/2d_engine_textures/assets/player32_red.png";
	enemy = new GameObject(filename2, 32, 0);

	map = new Map();
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
	player->Update();
	enemy->Update();
}

void Game::render(){
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
