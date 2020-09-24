#pragma once
#include<string>

#include"../operatorID/operatorID.hpp"

namespace server_side {

struct Solver {
	virtual std::string solve(OperatorID& prob) = 0;
};

}
