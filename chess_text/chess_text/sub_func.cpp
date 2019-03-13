#include "pch.hpp"

Point::Point(int yin, int xin) {
	x = xin;
	y = yin;
}
Point Point::operator-(Point p) {
	return Point(x - p.x, y - p.y);
}
Point Point::operator+(Point p) {
	return Point(x + p.x, y + p.y);
}
bool Point::operator==(Point p) {
	if (x == p.x && y == p.y) return true;
	else return false;
}
bool Point::operator!=(Point p) {
	if (x == p.x && y == p.y) return false;
	else return true;
}
int Point::move(Point next) {
	if (next.x < 0 || next.y < 0 || next.x >= 8 || next.y >= 8) return -1;
	x = next.x;
	y = next.y;
	return 0;
}