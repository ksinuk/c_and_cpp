// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

#ifndef PCH_H
#define PCH_H
#include <iostream>
#define MAXHISTORY 300
using namespace std;

enum Color { black = 1, white = 2 , none=0 };
enum Piece_type { king = 0, queen, rook, bishop, night, other };

class Point {
public:
	int x, y;
	Point(int yin, int xin);
	Point operator-(Point p);
	Point operator+(Point p);
	bool operator==(Point p);
	bool operator!=(Point p);
	int move(Point next);
};

inline Color turn_color(Color color) {
	if (color == black) return white;
	else if (color == white) return black;
	else return none;
}

#endif //PCH_H
