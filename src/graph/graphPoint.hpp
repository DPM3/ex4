#pragma once

#include<cstddef>
#include<unordered_map>

#include"direction.hpp"

namespace server_side {

class GraphPoint {
	size_t m_x, m_y;

public:
	//exceptions:
	struct NotAdjPoints : std::runtime_error {
		using std::runtime_error::runtime_error;
	};

	GraphPoint(size_t x = 0, size_t y = 0);

	size_t& x();
	size_t& y();

	size_t x() const;
	size_t y() const;

	bool operator==(GraphPoint other) const;
	bool operator!=(GraphPoint other) const;

	Direction dirTo(GraphPoint other) const;
};

}

namespace std { //don't panic :)

template<>
struct hash<server_side::GraphPoint> {
	size_t operator() (server_side::GraphPoint const& p) const;
};

}
