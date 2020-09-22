#include"gridParser.hpp"

#include<cstring>

#include"element.hpp"

namespace server_side {

Grid parseGrid(std::string const& input) {
	//unfortunately, the c++ standard library does not support everything I need(to split a string...), so I'm writing this in C.
	char* crep = strdup(input.data());
	char* iter = crep;

	//parse first line
	size_t height = std::atoi(strsep(&iter, "\n,"));
	size_t width = std::atoi(strsep(&iter, "\n,"));
	Grid result {width, height};

	//parse grid values
	int i = 0;
	for (char* line; (line = strsep(&iter, "\n")); ++i) {
		int j = 0;
		for (char* elem; (elem  = strsep(&line, ",")); ++j) {
			if (!std::strcmp(elem, "b")) {
				result(i,j) = Element::block();
			} else {
				result(i,j) = std::atof(elem);
			}
		}
	}
	free(crep);
	return result;
}

}
