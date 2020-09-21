#pragma once

#include"solver.hpp"

namespace server_side {

	class MySolver : public Solver {
		std::string solve(OperatorID& op) override;
	};

}
