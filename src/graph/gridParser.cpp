#include"gridParser.hpp"

#include<cstring>
#include<iostream>

#include"element.hpp"

namespace server_side {

Grid parseGrid(std::vector<std::string> const& input) {
	//unfortunately, the c++ standard library does not support everything I need(to split a string...), so I'm writing this in C.
	char* crep = strdup(input.at(0).data());
	char* iter = crep;
	//parse first line
	size_t height = std::atoi(strsep(&iter, "\n,"));
	size_t width = std::atoi(strsep(&iter, "\n,"));
	Grid result {width, height};
	free(crep);

	//parse grid values
	int i = 0;
	for (auto it = input.begin() + 1; it != input.end(); ++it, ++i) {
		std::string const& line = *it;
		char* lineCrep = strdup(line.data());
		char* lineIter = lineCrep;
		int j = 0;
		for (char* elem; (elem  = strsep(&lineIter, ",")); ++j) {
			if (!std::strcmp(elem, "b")) {
				result(j,i) = Element::block();
			} else {
				result(j,i) = std::atof(elem);
			}
		}
		free(lineCrep);
	}
	return result;
}

}
