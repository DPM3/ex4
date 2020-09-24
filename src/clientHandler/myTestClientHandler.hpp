#pragma once
#include"clientHandler.hpp"

namespace server_side {

class MyTestClientHandler : public ClientHandler {
	void handleClient( std::istream& is, std::ostream& os) const override;
};

}
