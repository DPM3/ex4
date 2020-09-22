#include"graphPointParser.hpp"

#include<cstring>

namespace server_side {

GraphPoint parseGraphPoint(std::string const& input) {
	char* crep = strdup(input.data());
	char* iter = crep;

	//parse first line
	size_t x = std::atoi(strsep(&iter, "\n,"));
	size_t y = std::atoi(strsep(&iter, "\n,"));
	free(crep);
	return GraphPoint{x, y};
}

}
