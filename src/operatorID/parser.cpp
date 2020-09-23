#include"parser.hpp"

#include<cstring>
#include<string>
#include<vector>
#include<iostream>

#include"myTestOperatorID.hpp"
#include"../graph/graphPoint.hpp"
#include"../graph/graphPointParser.hpp"
#include"../graph/gridParser.hpp"
#include"pathFindBFS.hpp"
//#include"pathFindAStar.hpp"
#include"pathFindDFS.hpp"

namespace server_side {

int OperatorIDParser::parseHeader(std::string const& content) {
	char* crep = strdup(content.c_str());
	char* iter = crep;

	std::vector<std::string> tokens(3);

	for (auto& s : tokens) {
		s = strsep(&iter, " \t\n");
	}

	if (tokens[0] == "solve") {
	} else {
		free(crep);
		return 2;
	}

	if (tokens[1] == "find-graph-path") {
	} else {
		free(crep);
		return 2;
	}

	if (tokens[2] == "BFS") {
		m_opType = POIDS::BFS;
	} else if (tokens[2] == "DFS") {
		m_opType = POIDS::DFS;
	} else if (tokens[2] == "A*") {
		m_opType = POIDS::AStar;
	} else if (tokens[2] == "BestFS") {
		m_opType = POIDS::BestFS;
	} else {
		free(crep);
		return 2;
	}

	free(crep);
	return 0;
}

OperatorID* OperatorIDParser::parseBody(std::string const& content) {
	char* crep = strdup(content.c_str());
	char* iter = crep;

	std::vector<std::string> lines;

	for (char* word; (word = strsep(&iter, "\n"));) {
		lines.push_back(word);
	}
	lines.pop_back();
	lines.pop_back(); //get rid of two empty lines

	GraphPoint end   = parseGraphPoint(lines.back());
	lines.pop_back();
	GraphPoint start = parseGraphPoint(lines.back());
	lines.pop_back();

	Grid grid = parseGrid(lines);
	switch (m_opType) {
		case POIDS::BFS:
			free(crep);
			std::cout << "newwww" << std::endl;
			return new PathFindBFS{grid, start, end};
		case POIDS::DFS:
			free(crep);
			//return new PathFindDFS{grid, start, end}; TODO: this class is not complete
			return new PathFindDFS{grid, start, end};
		case POIDS::AStar:
			free(crep);
			//return new PathFindAStar{grid, start, end}; TODO: this class is not complete
			return nullptr;
		case POIDS::BestFS:
			free(crep);
			//return new PathFindBestFS{grid, start, end};TODO this class is not complete
			return nullptr;
	}

	free(crep);
	return 0;
}

}
