#include"pathFindDFS.hpp"

#include<stack>
#include<map>
#include<unordered_map>
#include<algorithm>

#include"../graph/direction.hpp"
#include"../sha1/sha1.hpp"

namespace server_side {

std::string PathFindDFS::solve() const{
	std::stack<GraphPoint> s;
	//gives direction to the previous point in a course from start point
	std::unordered_map<GraphPoint, Direction> prevOnCourse{ {} };
	//distance from starting point (in steps)
	std::unordered_map<GraphPoint, size_t> distFromStart { {} };

	distFromStart[m_start] = 0;
	s.push(m_start);

	while (!s.empty()) {
		GraphPoint p = s.top();
		s.pop();

		//this loop checks for adjacent points to p,
		//and if they havn't been scanned yet by this very loop, then assign the dist and prev for that point.
		//
		//Notice that since we go in the same direction (in dfs style),
		//we will always get the first working path
		for (GraphPoint a : m_grid.adjPoints(p)) {
			if (distFromStart.find(a) == distFromStart.end()) { //checks if we already put a value for a
				s.push(a);
				distFromStart[a] = distFromStart[p] + 1;
				prevOnCourse[a] = a.dirTo(p);
			}
		}
	}
	if (distFromStart.find(m_end) == distFromStart.end()) {
		//TODO: return that there is no possible path to the end point.
		return "";
	} else {
		size_t cost = 0; //size_t because it really does need to be that big.
		std::vector<Direction> courseInv; //the course from end to start
		for (GraphPoint p = m_end; p != m_start; p = m_grid.getNeighbor(p,prevOnCourse[p])) {
			cost += m_grid(p).cost();
			courseInv.push_back(prevOnCourse[p]);
		}
		std::string result = std::to_string(cost);
		result += ",DFS";
		std::for_each(courseInv.rbegin(), courseInv.rend(), [&result](Direction dir) {
			result += "," + tostring(opposite(dir));
		});
		return result;
	}
}

std::string PathFindDFS::hash() const {
	std::string hashInput = "DFS";
	for (size_t i = 0; i < m_grid.height(); ++i) {
	for (size_t j = 0; j < m_grid.width (); ++j) {
		if (m_grid(j,i).isBlock()) {
			hashInput += "b ";
		} else {
			hashInput += std::to_string(m_grid(j,i).cost()) + " ";
		}
	}
	}

	hashInput += std::to_string(m_start.x()) + " ";
	hashInput += std::to_string(m_start.y()) + " ";

	hashInput += std::to_string(m_end.x()) + " ";
	hashInput += std::to_string(m_end.y()) + " ";

	//Now hashInput is a unique string for that specific OperatorID.
	//We will safely hash it, to get a unique string.
	//We use sha1, because this needs to be a very strong hash.
	return sha1(hashInput);
}

}
