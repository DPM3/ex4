#pragma once
#include"../clientHandler/clientHandler.hpp"

namespace server_side {

struct Server {
	virtual void open(int port, ClientHandler const& c) = 0;
	virtual void stop() = 0;
};

}
