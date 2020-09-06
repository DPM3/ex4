#pragma once
#include"point.hpp"

class Grid {
public:
	class Element {
		double m_val;
		bool m_isBlock;
	public:
		Element(double val = 0, bool isBlock = false);
		double& val();
		bool& isBlock();
		operator double(); //this is for convenience, does the same thing as val(), but read-only
	};

private:
	std::vector<Element> m_grid;
	int m_width, m_height;
public:
	Grid(int width, int height, std::vector<Element> grid = {});

	Element& operator() (int x, int y);
	Element& operator() (Point p);
};
