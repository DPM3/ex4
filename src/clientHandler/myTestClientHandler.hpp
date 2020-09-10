#pragma once
#include"clientHandler.hpp"

namespace server_side {

class MyTestClientHandler : public ClientHandler {
	void handleClient( std::istream const& is, std::ostream const& os) override;
};

}
