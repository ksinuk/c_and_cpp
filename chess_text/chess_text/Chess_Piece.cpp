#include "pch.hpp"
#include "Piece.hpp"
#include "Map.hpp"

extern string map_out[8][8];
extern Map map;

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

int Piece::move(Point next) {//캐슬링은 별도의 함수를 사용한다.
	if (point == next) return -1;
	Point temp = next - point;

	switch (type)
	{
	case king:
		if (int_abs(temp.x)>2 || int_abs(temp.y) > 2) return -1;
		Color you_color = turn_color(color);
		if (map.color[you_color][next.y][next.x]) return -1;
		break;
	case queen:
		if (int_abs(temp.x) != int_abs(temp.y) && temp.x != 0 && temp.y != 0) return -1;
		break;
	case rook:
		if (int_abs(temp.x) != int_abs(temp.y)) return -1;
		break;
	case bishop:
		if (temp.x != 0 && temp.y != 0) return -1;
		break;
	case night:
		if (int_abs(temp.x)==2 && int_abs(temp.y) ==1 || int_abs(temp.x) == 1 && int_abs(temp.y) == 2) return -1;
		break;
	default:
		break;
	}
	int dx= temp.x, dy = temp.y;
	if (type != night) {
		dx = ((temp.x == 0) ? 0 : (temp.x / int_abs(temp.x)));
		dy = ((temp.y == 0) ? 0 : (temp.y / int_abs(temp.y)));
	}

	Point d = Point(dx, dy);

	Point start = Point(point.x + dx, point.y + dy);
	while (start != next) {
		if (map_out[start.y][start.x] != "  ") return -1;
		start = start + d;
	}

	first_move++;
	point.move(next);
	return 0;
}


