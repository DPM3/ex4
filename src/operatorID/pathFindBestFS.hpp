#pragma once

#include"pathFind.hpp"

namespace server_side {

class PathFindBestFS : public PathFind {
	using PathFind::m_grid;
	using PathFind::m_start;
	using PathFind::m_end;

	int distanceFromEnd(GraphPoint p) const;
public:
	std::string solve() const override;
	std::string hash () const override;
	using PathFind::PathFind;
};

}
