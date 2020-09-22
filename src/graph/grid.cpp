#include"grid.hpp"

namespace server_side {

Grid::Grid(std::initializer_list<std::initializer_list<Element>> init)
	: m_width{init.begin()->size()}, m_height{init.size()}, m_data(m_width * m_height) {

	for (auto&& list : init) {
	for (auto&& elem : list) {
		m_data.emplace_back(elem);
	}
	}
}

Element& Grid::operator() (size_t i, size_t j) {
	return m_data[i * width() + j];
}

Element  Grid::operator() (size_t i, size_t j) const {
	return m_data[i * width() + j];
}

Element& Grid::operator() (GraphPoint const& p) {
	return (*this)(p.x(), p.y());
}

Element  Grid::operator() (GraphPoint const& p) const {
	return (*this)(p.x(), p.y());
}

Element getNeighbor(GraphPoint p, Direction d) {
	switch:
		case UP:
			return (*this)(p.x(), p.y() - 1);
		case DOWN:
			return (*this)(p.x(), p.y() + 1);
		case RIGHT:
			return (*this)(p.x() + 1, p.y());
		case LEFT:
			return (*this)(p.x() - 1, p.y());
}

size_t Grid::width() const {
	return m_width;
}
size_t Grid::height() const {
	return m_height;
}

}
