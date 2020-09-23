#pragma once

#include"pathFind.hpp"

namespace server_side {

class PathFindAStar : public PathFind {
    using PathFind::m_grid;
    using PathFind::m_start, PathFind::m_end;

	distanceFromEnd(GraphPoint p);
public:
    PathFindAStar(Grid grid, Point start, Point end);
    std::string solve() const override;
};

}
