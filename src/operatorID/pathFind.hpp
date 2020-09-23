#pragma once

#include"operatorID.hpp"
#include"../graph/grid.hpp"
#include"../graph/graphPoint.hpp"

namespace server_side {

class PathFind : public OperatorID {
protected:
	Grid m_grid;
	GraphPoint m_start, m_end;
public:
	PathFind(Grid grid, GraphPoint start, GraphPoint end);
};

}
