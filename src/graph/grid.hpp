#pragma once

#include<vector>
#include<cstddef>

#include"element.hpp"
#include"graphPoint.hpp"
#include"direction.hpp"

namespace server_side {

class Grid {
	size_t m_width, m_height;
	std::vector<Element> m_data;
public:
	//exceptions:
	struct NeighborPointInvalid : public std::runtime_error {
		using std::runtime_error::runtime_error; //borrow the constructor
	};

	Grid(std::initializer_list<std::initializer_list<Element>> init);
	Grid(size_t height, size_t width);

	Element& operator() (size_t i, size_t j);
	Element  operator() (size_t i, size_t j) const;

	Element& operator() (GraphPoint const& p);
	Element  operator() (GraphPoint const& p) const;

	size_t width() const;
	size_t height() const;

	GraphPoint getNeighbor(GraphPoint const& p, Direction const& d) const;
	std::vector<GraphPoint> adjPoints(GraphPoint const& p) const;
};

}
