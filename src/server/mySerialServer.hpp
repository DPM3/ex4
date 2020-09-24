#pragma once

#include<sys/socket.h>
#include<thread>
#include<atomic>

#include"server.hpp"

namespace server_side {

class MySerialServer : public Server {
	std::thread m_serverThread;
	std::atomic_bool m_stop;
public:
	MySerialServer() : m_serverThread{}, m_stop{false} { }
	void open(int port, ClientHandler const& c) override;
	void stop() override;
};

}
