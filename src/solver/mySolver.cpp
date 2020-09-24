#include"mySolver.hpp"

namespace server_side {

std::string MySolver::solve(OperatorID& op) {
	return op.solve();
}

}
