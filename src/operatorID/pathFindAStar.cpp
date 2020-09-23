#include"pathFindAStar.hpp"

#include<queue>
#include<map>
#include<unordered_map>
#include<pair>

#include"../graph/direction.hpp"

namespace server_side {

int PathFinderAStar::distanceFromEnd(GraphPoint p) {
	return 10 * (abs(p.getX() - m_end.getX()) + abs(p.getY() - m_end.getY())) -
			6 * std::min(abs(p.getX() - m_end.getX()), abs(p.getY() - m_end.getY()));
}

std::string PathFindAStar::solve() const{
    std::queue<std::pair<GraphPoint, int>> q;
    //gives direction to the previous point in a course from start point
    std::unordered_map<GraphPoint, Direction> prevOnCourse{ {} };
    //distance from starting point (in steps)
    std::unordered_map<GraphPoint, size_t> distFromStart { {} };

    distFromStart[m_start] = 0;
    q.push(m_start, 0);

    while (!q.empty()) {

		std::pair current = q.front();

		for (std::pair pair : q) {
			if (std::pair.get<1>(pair) + distance(std::pair.get<0>(pair), m_end) <
				std::pair.get<1>(current) + distance(std::pair.get<0>(current), m_end)) {
				current = std::pair.get<0>(pair);
			}
		}

        GraphPoint p = std::get<0>(current);
        q.pop();

        //this loop checks for adjacent points to p,
        //and if they havn't been scanned yet by this very loop, then assign the dist and prev for that point.
        //
        //Notice that since we go in the same direction (in dfs style),
        //we will always get the first working path
        for (GraphPoint a : getAdjTo(p)) {
            if (distFromStart.find(a) == distFromStart.end()) { //checks if we already put a value for a
                q.push(a, std::get<1>(current) + m_grid(a));
                distFromStart[a] = distFromStart[p] + 1;
                prevOnCourse[a] = p;
            }
        }
    }
    if (distFromStart.find(m_end) == distFromStart.end()) {
        //TODO: return that there is no possible path to the end point.
        return "";
    } else {
        std::vector<Direction> courseInv; //the course from end to start
        for (GraphPoint p = m_end; p != m_start; p = applyDir(p,prevOnCourse[p])) {
            courseInv.push_back(prevOnCourse[p]);
        }
        std::string str = "";
        for (Direction d : courseInv) {
            str += tostring(d);
        }
        return str;
    }
}
