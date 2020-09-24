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
		int status = m_idParser.parseHeader(input);
		os << "Version: 1.0.0" << std::endl;
		os << "status: " << status << std::endl;
		os << "response-length: 0" << std::endl;
		os << std::endl << std::endl;
		return;
	}
	std::unique_ptr<OperatorID> op {m_idParser.parseBody(input)};
	if (m_cacheManager->isInCache(*op)) {
		os << m_cacheManager->getResult(*op);
	} else {
		os << "Version: 1.0.0" << std::endl;
		std::string result;
		try {
		result = m_solver->solve(*op);
		} catch(...) {
			os << "status: 2" << std::endl;
			os << "response-length: 0" << std::endl;
			return;
		}
		if (result == "") {
			os << "status: 1" << std::endl;
			os << "response-length: 0" << std::endl;
			return;
		}
		os << "status: 0" << std::endl;
		os << "response-length: " << result.size() << std::endl;
		os << result;
		os << std::endl << std::endl;
		m_cacheManager->addOp(*op, result);
	}
}

ClientHandler* MyClientHandler::clone() const {
	return new MyClientHandler(*this);
}

}
