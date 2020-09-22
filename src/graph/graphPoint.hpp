#pragma once

#include<cstddef>

namespace server_side {

class GraphPoint {
	size_t m_x, m_y;

public:
	GraphPoint(size_t x = 0, size_t y = 0);

	size_t& x();
	size_t& y();

	size_t x() const;
	size_t y() const;
};

}
