#include"pathFindDFS.hpp"

#include<stack>
#include<map>
#include<unordered_map>

#include"../graph/direction.hpp"

namespace server_side {

std::string PathFindBFS::solve() const{
    std::stack<GraphPoint> s;
    //gives direction to the previous point in a course from start point
    std::unordered_map<GraphPoint, Direction> prevOnCourse{ {} };
    //distance from starting point (in steps)
    std::unordered_map<GraphPoint, size_t> distFromStart { {} };

    distFromStart[m_start] = 0;
    s.push(m_start);

    while (!q.empty()) {
        GraphPoint p = s.front();
        s.pop();

        //this loop checks for adjacent points to p,
        //and if they havn't been scanned yet by this very loop, then assign the dist and prev for that point.
        //
        //Notice that since we go in the same direction (in dfs style),
        //we will always get the first working path
        for (GraphPoint a : getAdjTo(p)) {
            if (distFromStart.find(a) == distFromStart.end()) { //checks if we already put a value for a
                s.push(a);
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
