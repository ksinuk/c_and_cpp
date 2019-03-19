#pragma once
#ifndef PIECE_H
#define PIECE_H

class Map;

class Piece {//폰을 제외한 기물
protected:
	Point point = Point(0, 0);
	Color color;
	Piece_type type;

	int first_move;
public:
	Piece();
	Piece(Color colorin, Piece_type typein, int y, int x);
	int move(Point next, Map &map);//캐슬링은 별도의 함수를 사용한다.
	int castling(Piece &rook, Map &map);
};

class Pawn {
protected:
	Point point = Point(0, 0);
	Color color;
	int first_move;
	int en_passant;

	Pawn();
	int move(Point next);
	int Promotion();


};


#endif
