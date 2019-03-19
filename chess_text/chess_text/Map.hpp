#ifndef MAP_H
#define MAP_H

class Piece;

class Map
{
public:
	Piece *map[8][8];
	int color[3][8][8];
	string out[8][8];

	Map();
	~Map();
};


#endif //MAP_H

