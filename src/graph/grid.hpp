#pragma once

#include<vector>
#include<cstddef>

#include"element.hpp"
#include"graphPoint.hpp"

namespace server_side {

class Grid {
	size_t m_width, m_height;
	std::vector<Element> m_data;
public:
	Grid(std::initializer_list<std::initializer_list<Element>> init);

	Element& operator() (size_t i, size_t j);
	Element  operator() (size_t i, size_t j) const;

	Element& operator() (GraphPoint const& p);
	Element  operator() (GraphPoint const& p) const;

	size_t width() const;
	size_t height() const;
};

}
