#pragma once

#include<sys/socket.h>

#include"server.hpp"

namespace server_side {

class MySerialServer : public Server {
	void open(int port, ClientHandler const& c) override;
	void stop() override;
};

}
