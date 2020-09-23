#pragma once

#include"pathFind.hpp"

namespace server_side {

class PathFindAStar : public PathFind {
    using PathFind::m_grid;
    using PathFind::m_start, PathFind::m_end;

	distanceFromEnd(GraphPoint p);
public:
    std::string solve() const override;
};

}
