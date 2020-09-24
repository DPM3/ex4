#include"sha1.hpp"

namespace server_side {

//this file is an implementation of sha1 we found online.
extern "C" {
#include"sha1Lib.c"
}

std::string sha1(std::string const& content) {
	char result[41];

	//I know I'm using NULL, it's because this is a C func
	sha1digest(NULL, result, reinterpret_cast<const uint8_t*>(content.c_str()), content.size()+1);

	return std::string {result};
}

}
