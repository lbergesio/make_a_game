#include "game.h"

SDL_Texture*  playerTex;
SDL_Rect srcR, dstR;

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

	SDL_Surface* tmpSurface = IMG_Load("src/2d_engine_textures/player.png");
	if(!tmpSurface){
		std::cout << "Texture player not found!" << std::endl;
		exit(1);
	}
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
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
	cnt++;

	dstR.h = 64;
	dstR.w = 64;
	dstR.x = cnt;

	std::cout << cnt << std::endl;
}

void Game::render(){
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, playerTex, NULL, &dstR);
	SDL_RenderPresent(renderer);
}

void Game::clean(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}
