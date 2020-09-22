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

namespace std {

size_t hash<server_side::GraphPoint>::operator() (server_side::GraphPoint const& p) const {
		return hash<size_t>{}(p.x()) ^ (hash<size_t>{}(p.y()) << 1) >> 1; //common way of hashing multiple objects together
}

}
