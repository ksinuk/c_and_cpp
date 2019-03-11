#include <iostream>
using namespace std;

enum Color {black=0,white=1};

class Point {
public:
	int x,y;
	Point(int xin, int yin) {
		x = xin;
		y = yin;
	}
	Point operator-(Point p) {
		return Point(x - p.x, y - p.y);
	}
	bool operator==(Point p) {
		if (x == p.x && y == p.y) return true;
		else return false;
	}

	void abs() {
		x = (x > 0) ? x : -x;
		y = (y > 0) ? y : -y;
	}
	int move(Point next) {
		if (next.x < 0 || next.y < 0 || next.x >= 8 || next.y >= 8) return -1;
		x = next.x;
		y = next.y;
		return 0;
	}
};

class Piece {
protected:
	Point point = Point(0, 0);
	Color color;
	Piece() {}
};

class King:public Piece {
	int first_move;
	King(Color colorin) {
		first_move = 0;
		color = colorin;
		if (color == black) point = Point(4,0);
		else point = Point(4, 7);
	}
	int move(Point next) {//캐슬링은 별도의 함수를 사용한다.
		if (point == next) return -1;
		Point temp = point-next;
		temp.abs();

		if (temp.x > 1 || temp.y>1) return -1;
		else {
			first_move++;
			point.move(next);
			return 0;
		}
	}
};

class Queen :public Piece {
	Queen(Color colorin) {
		color = colorin;
		if (color == black) point = Point(3, 0);
		else point = Point(3, 7);
	}
	int move(Point next) {
		if (point == next) return -1;
		Point temp = point - next;
		temp.abs();

		if (temp.x!=temp.y && temp.x!=0 && temp.y!=0) return -1;
		else {
			point.move(next);
			return 0;
		}
	}
};