#include<iostream>
#include<cstring>
#include<memory>

#include"server/mySerialServer.hpp"
#include"server/myParallelServer.hpp"
#include"clientHandler/myClientHandler.hpp"
#include"solver/mySolver.hpp"
#include"cacheManager/fileCacheManager/fileCacheManager.hpp"
using namespace server_side;

int main(int argc, char** argv) {
	bool isParallel = true;
	if (argc < 2) {
		std::cout << "error: not enough args" << std::endl;
		return 1;
	} else if (argc == 2) {
		isParallel = true;
	} else if (argc == 3) {
		if (!strcmp(argv[2], "parallel")) {
			isParallel = true;
		} else if (!strcmp(argv[2], "serial")) {
			isParallel = false;
		}
	} else {
		std::cout << "error: too many args" << std::endl;
	}
	const int port = atoi(argv[1]);
	std::unique_ptr<Server> server;
	if (isParallel) {
		server = std::make_unique<MyParallelServer>();
	} else {
		server = std::make_unique<MySerialServer>();
	}
	server->open(port, MyClientHandler{MySolver{}, FileCacheManager{"./cache"}});
	if (getchar() == 's') {
		server->stop();
	}
}
