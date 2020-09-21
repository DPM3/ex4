#include"myTestOperatorID.hpp"

namespace server_side {
std::string MyTestOperatorID::hash() const {
	return "0000000000000000000000000000000000000000"; //exactly 40 zeroes :)
}

std::string MyTestOperatorID::solve() const {
	return "test solve!";
}
MyTestOperatorID::~MyTestOperatorID() { }

}
