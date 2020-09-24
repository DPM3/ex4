#include<iostream>

#include"server/mySerialServer.hpp"
#include"clientHandler/myClientHandler.hpp"
#include"solver/mySolver.hpp"
#include"cacheManager/fileCacheManager/fileCacheManager.hpp"
using namespace server_side;

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cout << "error: not enought args" << std::endl;
		return 1;
	}
	const int port = atoi(argv[1]);
	MySerialServer server {};
	server.open(port, MyClientHandler{MySolver{}, FileCacheManager{"./cache"}});
	if (getchar() == 's') {
		server.stop();
	}
}
