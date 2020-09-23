#pragma once

#include"clientHandler.hpp"
#include"../solver/solver.hpp"
#include"../cacheManager/cacheManager.hpp"
#include"../operatorID/parser.hpp"

namespace server_side {

class MyClientHandler : public ClientHandler {
	Solver* m_solver;
	CacheManager* m_cacheManager;
	mutable OperatorIDParser m_idParser;
public:
	MyClientHandler(Solver* solver, CacheManager* cacheManager);
	MyClientHandler(Solver&& solver, CacheManager&& cacheManager);
	void handleClient(std::istream& is, std::ostream& os) const override;
};

}
