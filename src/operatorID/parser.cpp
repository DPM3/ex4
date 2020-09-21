#include"parser.hpp"

#include"myTestOperatorID.hpp"

namespace server_side {

OperatorID* parseToOperatorID(std::string content) {
	(void)content;
	return new MyTestOperatorID{};
}

}
