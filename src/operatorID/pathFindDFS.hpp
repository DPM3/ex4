#pragma once

#include"pathFind.hpp"

namespace server_side {

class PathFindDFS : public PathFind {
    using PathFind::m_grid;
    using PathFind::m_start, PathFind::m_end;
public:
	PathFindDFS(Grid grid, Point start, Point end);
    std::string solve() const override;
};

}
