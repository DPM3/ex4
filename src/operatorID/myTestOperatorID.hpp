#pragma once

#include"operatorID.hpp"

namespace server_side {

class MyTestOperatorID : public OperatorID {
public:
	std::string hash() const override;
	std::string solve() const override;
	~MyTestOperatorID() override;
};

}
