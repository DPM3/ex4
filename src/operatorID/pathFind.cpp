#include"pathFind.hpp"

namespace server_side {

PathFind::PathFind(Grid grid, GraphPoint start, GraphPoint end) 
	: m_grid{grid}, m_start{start}, m_end{end} { }

}
