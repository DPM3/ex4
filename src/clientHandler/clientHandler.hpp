#pragma once
#include<iostream>
namespace server_side {

struct ClientHandler {
	virtual void handleClient( std::istream const& is, std::ostream const& os) = 0;
};

}
