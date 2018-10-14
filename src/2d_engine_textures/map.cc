#include "map.h"
#include "texture_manager.h"

int lvl1[20][25] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map(){
	dirt = TextureManager::LoadTexture("src/2d_engine_textures/assets/dirt.png");
	grass = TextureManager::LoadTexture("src/2d_engine_textures/assets/grass.png");
	water = TextureManager::LoadTexture("src/2d_engine_textures/assets/water.png");

	LoadMap(lvl1);

	src.x = src.y = 0;
	src.w = src.h = 32;

	dst.x = dst.y = 0;
	dst.w = dst.h = 32;
}

void Map::LoadMap(int arr[20][25]){
	for(int row = 0; row < 20; ++row){	
		for(int col = 0; col < 25; ++col){
			map[row][col] = lvl1[row][col];
		}
	}
}

void Map::DrawMap(){
	int type = 0;

	for(int row = 0; row < 20; ++row){	
		for(int col = 0; col < 25; ++col){
			type = map[row][col];

			dst.x = col*32;
			dst.y = row*32;

			switch(type){
			case 0:
				TextureManager::Draw(water, src, dst);
				break;
			case 1:
				TextureManager::Draw(grass, src, dst);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dst);
				break;
			default:
				break;
			}
		}
	}
}
