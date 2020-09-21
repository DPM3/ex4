#pragma once

#include"clientHandler.hpp"
#include"../solver/solver.hpp"
#include"../cacheManager/cacheManager.hpp"

namespace server_side {

class MyClientHandler : public ClientHandler {
	Solver& m_solver;
	CacheManager& m_cacheManager;
public:
	MyClientHandler(Solver const& solver, CacheManager const& cacheManager);
	void handleClient(std::istream& is, std::ostream& os) const override;
};

}
