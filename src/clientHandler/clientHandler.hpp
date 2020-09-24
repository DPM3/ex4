#pragma once
#include<iostream>
namespace server_side {

struct ClientHandler {
	virtual void handleClient(std::istream& is, std::ostream& os) const = 0;
	virtual ClientHandler* clone() const = 0;
};

}
