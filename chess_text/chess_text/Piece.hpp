#pragma once
#ifndef PIECE_H
#define PIECE_H

class Map;

class Piece {//���� ������ �⹰
protected:
	Point point = Point(0, 0);
	Color color;
	Piece_type type;
	int first_move;

	int en_passant;
	Arrow arrow;

public:
	Piece();
	Piece(Color colorin, Piece_type typein, int y, int x, Arrow arrowin);
	int move(Point next, Map &map);//ĳ������ ������ �Լ��� ����Ѵ�.
	int castling(Piece &rook, Map &map);
	int Promotion();
	int enpassant();

	Color iscolor();
 
};


#endif
