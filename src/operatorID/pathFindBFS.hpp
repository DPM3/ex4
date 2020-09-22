#pragma once

#include"pathFind.hpp"

namespace server_side {

class PathFindBFS : public PathFind {
	using PathFind::m_grid;
	using PathFind::m_start, PathFind::m_end;
public:
	std::string solve() const override;
};

}
