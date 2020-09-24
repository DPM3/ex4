#include"myTestClientHandler.hpp"
#include<string>

namespace server_side {

void MyTestClientHandler::handleClient( std::istream& is, std::ostream& os) const {
	std::string content ((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
	os << content;
}

}
