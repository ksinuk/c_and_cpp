#include "pch.hpp"
#include "Map.hpp"
#include "Piece.hpp"

Map::Map()
{
	for(int y=0;y<8;y++)
		for (int x = 0; x < 8; x++) {
			map[y][x] = NULL;	
			color[0][y][x] = 0;
			color[1][y][x] = 0;
			out[y][x] = "  ";
		}
}


Map::~Map()
{
}
