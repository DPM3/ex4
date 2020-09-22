#include"graphPoint.hpp"

namespace server_side {

GraphPoint::GraphPoint(size_t x, size_t y) : m_x{x}, m_y{y}{ }

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

bool GraphPoint::operator==(GraphPoint other) {
	return x() == other.x() && y() == other.y();
}
bool GraphPoint::operator!=(GraphPoint other) {
	return !(*this == other);
}

}
