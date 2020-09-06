#include"grid.hpp"

Grid::Element::Element(double val, bool isBlock) : m_val(val), m_isBlock(isBlock) { }

double& Grid::Element::val() {
	return m_val;
}

bool& Grid::Element::isBlock() {
	return m_isBlock;
}

Grid::Element::operator double() {
	return m_val;
}
