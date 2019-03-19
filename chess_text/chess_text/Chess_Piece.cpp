#include "pch.hpp"
#include "Piece.hpp"
#include "Map.hpp"


Piece::Piece() {
	first_move = 0;
	color = none;
	point = Point(-1, -1);
}
Piece::Piece(Color colorin, Piece_type typein, int y,int x) {
		first_move = 0;
		color = colorin;
		type = typein;
		point = Point(y, x);

	}

int Piece::move(Point next , Map &map) {//캐슬링은 별도의 함수를 사용한다.
	if (point == next) return -1;
	Point temp = next - point;
	Color you_color;

	switch (type)
	{
		case king:
			if (abs(temp.x)>2 || abs(temp.y) > 2) return -1;
			you_color = turn_color(color);
			if (map.color[you_color][next.y][next.x]) return -1;
			break;
		case queen:
			if (abs(temp.x) != abs(temp.y) && temp.x != 0 && temp.y != 0) return -1;
			break;
		case rook:
			if (abs(temp.x) != abs(temp.y)) return -1;
			break;
		case bishop:
			if (temp.x != 0 && temp.y != 0) return -1;
			break;
		case night:
			if (abs(temp.x)==2 && abs(temp.y) ==1 || abs(temp.x) == 1 && abs(temp.y) == 2) return -1;
			break;
		default:
			break;
	}
	int dx= temp.x, dy = temp.y;
	if (type != night) {
		dx = ((temp.x == 0) ? 0 : (temp.x / abs(temp.x)));
		dy = ((temp.y == 0) ? 0 : (temp.y / abs(temp.y)));
	}

	Point d = Point(dx, dy);

	Point start = Point(point.x + dx, point.y + dy);
	while (start != next) {
		if (map.map[start.y][start.x] != NULL) return -1;
		start = start + d;
	}

	map.map[point.y][point.x] = NULL;
	first_move++;
	point.move(next);
	map.map[point.y][point.x] = this;

	return 0;
}

int Piece::castling(Piece &rook, Map &map) { //킹 piece에서 호출
	if (first_move!=0 || rook.first_move!=0) return -1;

	int y = point.y;
	int dx = rook.point.x - point.x;
	dx = dx / abs(dx);
	for (int x = point.x + 1; x != rook.point.x; x += dx) {
		if (map.map[y][x] != NULL) return -1;
	}
	int kx = point.x;
	Color you = turn_color(color);
	if (map.color[you][y][kx] != 0 || map.color[you][y][kx+dx] != 0 || map.color[you][y][kx+dx+dx] != 0) return -1;

	map.map[y][point.x] = NULL;
	map.map[y][rook.point.x] = NULL;

	first_move++;
	point.x += dx + dx;
	rook.point.x = point.x - dx;
	rook.first_move++;

	map.map[y][point.x] = this;
	map.map[y][rook.point.x] = &rook;

	return 0;
}

