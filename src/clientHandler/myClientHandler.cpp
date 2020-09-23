#include"myClientHandler.hpp"

#include<memory>

#include"../operatorID/parser.hpp"
#include"../operatorID/operatorID.hpp"

namespace server_side {

MyClientHandler::MyClientHandler(Solver* solver, CacheManager* cacheManager)
	: m_solver{solver}, m_cacheManager{cacheManager} { }

MyClientHandler::MyClientHandler(Solver&& solver, CacheManager&& cacheManager)
	: MyClientHandler{&solver, &cacheManager} { }

void MyClientHandler::handleClient(std::istream& is, std::ostream& os) const {
	std::string input ((std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>());
	if (input.substr(0,6) == "solve " || input.substr(0,6) == "solve\t") {
		m_idParser.parseHeader(input);
		os << "Version: 1.0.0" << std::endl;
		return;
	}
	std::unique_ptr<OperatorID> op {m_idParser.parseBody(input)};
	std::cout << "parsed header!" << std::endl;
	if (m_cacheManager->isInCache(*op)) {
		os << m_cacheManager->getResult(*op);
	} else {
		std::string result = m_solver->solve(*op);
		m_cacheManager->addOp(*op, result);
		os << result;
	}
}

}
