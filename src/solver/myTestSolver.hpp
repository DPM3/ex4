#pragma once

#include"solver.hpp"

namespace server_side {

	class MyTestSolver : public Solver {
		std::string solve(OperatorID op) override;
	};

}
