#include"graphPoint.hpp"

namespace server_side {

GraphPoint::GraphPoint(size_t x = 0, size_t y = 0) : m_x{x}, m_y{y}{ }

size_t& GraphPoint::x() {
	return m_x;
}
size_t& GraphPoint::y() {
	return m_y;
}

size_t GraphPoint::x() const {
	return m_x;
}
size_t GraphPoint::y() const {
	return m_y;
}

}
