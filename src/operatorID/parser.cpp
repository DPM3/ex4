#include"parser.hpp"

#include<cstring>
#include<string>
#include<vector>

#include"myTestOperatorID.hpp"

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

	for (char* word; (word = strsep(&iter, "\n")); lines.push_back(word)) { }

	free(crep);
	return 0;
}

}
