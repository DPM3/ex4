#include"pathFindAStar.hpp"

#include<list>
#include<map>
#include<unordered_map>
#include<utility>
#include<algorithm>

#include"../graph/direction.hpp"
#include"../sha1/sha1.hpp"

namespace server_side {

int PathFindAStar::distanceFromEnd(GraphPoint p) const {
	return 10 * (abs((int)p.x() - (int)m_end.x()) + abs((int)p.y() - (int)m_end.y())) -
			6 * std::min(abs((int)p.x() - (int)m_end.y()), abs((int)p.y() - (int)m_end.y()));
}

std::string PathFindAStar::solve() const{
	std::list<std::pair<GraphPoint, int>> l;
	//gives direction to the previous point in a course from start point
	std::unordered_map<GraphPoint, Direction> prevOnCourse{ {} };
	//distance from starting point (in steps)
	std::unordered_map<GraphPoint, size_t> distFromStart { {} };

	distFromStart[m_start] = 0;
	l.push_back({m_start, 0});

	while (!l.empty()) {

		std::pair<GraphPoint, int> current = l.front();

		for (auto pair : l) {
			if (std::get<1>(pair) + distanceFromEnd(std::get<0>(pair)) <
				std::get<1>(current) + distanceFromEnd(std::get<0>(current))) {
				current = pair;
			}
		}

		GraphPoint p = std::get<0>(current);
		l.pop_front();

		//this loop checks for adjacent points to p,
		//and if they havn't been scanned yet by this very loop, then assign the dist and prev for that point.
		//
		//Notice that since we go in the same direction (in dfs style),
		//we will always get the first working path
		for (GraphPoint a : m_grid.adjPoints(p)) {
			if (distFromStart.find(a) == distFromStart.end()) { //checks if we already put a value for a
				l.push_back({a, std::get<1>(current) + m_grid(a).cost()});
				distFromStart[a] = distFromStart[p] + 1;
				prevOnCourse[a] = a.dirTo(p);
			}
		}
	}
	if (distFromStart.find(m_end) == distFromStart.end()) {
		return ""; //no solution
	} else {
		size_t cost = 0; //size_t because it really does need to be that big.
		std::vector<Direction> courseInv; //the course from end to start
		for (GraphPoint p = m_end; p != m_start; p = m_grid.getNeighbor(p,prevOnCourse[p])) {
			cost += m_grid(p).cost();
			courseInv.push_back(prevOnCourse[p]);
		}
		std::string result = std::to_string(cost);
		result += ",A*";
		std::for_each(courseInv.rbegin(), courseInv.rend(), [&result](Direction dir) {
			result += "," + tostring(opposite(dir));
		});
		return result;
	}
}

std::string PathFindAStar::hash() const {
	std::string hashInput = "A*";
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
