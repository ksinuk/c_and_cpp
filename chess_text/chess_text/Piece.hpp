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
public:
	Piece();
	Piece(Color colorin, Piece_type typein, int y, int x);
	int move(Point next, Map &map);//ĳ������ ������ �Լ��� ����Ѵ�.
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
