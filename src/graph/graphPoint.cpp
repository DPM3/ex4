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

bool GraphPoint::operator==(GraphPoint other) const {
	return x() == other.x() && y() == other.y();
}
bool GraphPoint::operator!=(GraphPoint other) const {
	return !(*this == other);
}

Direction GraphPoint::dirTo(GraphPoint other) const {
	int xDist = x() - other.x();
	int yDist = y() - other.y();

	if (xDist == 1 && yDist == 0) {
		return Direction::LEFT;
	} else if (xDist == -1 && yDist == 0) {
		return Direciton::RIGHT;
	} else if (xDist == 0 && yDist == 1) {
		return Direction::UP;
	} else if (xDist == 0 && yDist == -1) {
		return Direction::DOWN;
	} else {
		throw NotAdjPoints{"points are not ajdacent, so can't determince derection between them."};
	}
}

}

namespace std {

size_t hash<server_side::GraphPoint>::operator() (server_side::GraphPoint const& p) const {
		return hash<size_t>{}(p.x()) ^ (hash<size_t>{}(p.y()) << 1) >> 1; //common way of hashing multiple objects together
}

}
