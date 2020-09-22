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

GraphPoint Grid::getNeighbor(GraphPoint const& p, Direction const& d) const {
	switch (d) {
		case Direction::UP:
			if (p.y() - 1 < 0) {
				throw NeighborPointInvalid{"neighbor point does not exist"};
			}
			return GraphPoint{p.x(), p.y() - 1};
		case Direction::DOWN:
			if (p.y() + 1 >= height()) {
				throw NeighborPointInvalid{"neighbor point does not exist"};
			}
			return GraphPoint{p.x(), p.y() + 1};
		case Direction::RIGHT:
			if (p.x() + 1 >= width()) {
				throw NeighborPointInvalid{"neighbor point does not exist"};
			}
			return GraphPoint{p.x() + 1, p.y()};
		case Direction::LEFT:
			if (p.x() - 1 < 0) {
				throw NeighborPointInvalid{"neighbor point does not exist"};
			}
			return GraphPoint{p.x() - 1, p.y()};
	}
}

std::vector<GraphPoint> Grid::adjPoints(GraphPoint const& p) const {
	std::vector<GraphPoint> result (4); //should definitely improve run time, even if not all 4 slots are used
	Direction allDirs[] = {Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT};
	for (auto d : allDirs) {
		try {
			GraphPoint adjUp = this->getNeighbor(p, d);
			if ( !(*this)(adjUp).isBlock() ) {
				result.emplace_back(adjUp);
			}
		} catch (NeighborPointInvalid&) { }
	}
	return result;
}

size_t Grid::width() const {
	return m_width;
}
size_t Grid::height() const {
	return m_height;
}

}
