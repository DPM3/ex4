#pragma once

class Point {
	int m_x, m_y;
public:
	Point(int x = 0, int y = 0) : m_x(x), m_y(y) { }
	int& x();
	int& y();
};
