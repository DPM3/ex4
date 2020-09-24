#include<iostream>
#include<thread>
#include<arpa/inet.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>

#include"../server/mySerialServer.hpp"
#include"../clientHandler/myClientHandler.hpp"
#include"../solver/mySolver.hpp"
#include"../cacheManager/fileCacheManager/fileCacheManager.hpp"

int main() {
	const std::vector<std::pair<std::string, std::string>> cmds = {
		{"solve find-graph-path BFS\n\n", "3,3\n1,2,3\n4,5,6\n7,8,9\n0,0\n2,2\n\n"},
		{"solve find-graph-path DFS\n\n", "2,3\nb,1,1\n1,1,b\n0,0\n1,2\n\n"},
		{"solve find-graph-path BestFS\n\n", "3,3\n1,2,3\n4,5,6\n7,8,9\n0,0\n2,2\n\n"},
		{"solve find-graph-path A*\n\n", "2,3\nb,1,1\n1,1,b\n0,0\n1,2\n\n"}
	};

	const int port = 8082;

	server_side::MySerialServer mss;
	mss.open(port, server_side::MyClientHandler{ server_side::MySolver{}, server_side::FileCacheManager{"./cache"} });

	for (std::pair<std::string, std::string> cmd : cmds) {
		const int sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0) {
			throw std::system_error { errno, std::system_category() };
		}

		sockaddr_in connectAddress{};
		if (0 == inet_aton("127.0.0.1", &connectAddress.sin_addr)) {
			close(sockfd);
			throw std::runtime_error{"Failed converting IP to 4-bytes"};
		}
		connectAddress.sin_family = AF_INET;
		connectAddress.sin_port = htons(port);

		if (connect(sockfd, reinterpret_cast<const sockaddr*>(&connectAddress), sizeof(connectAddress)) < 0) {
			close(sockfd);
			throw std::system_error { errno, std::system_category() };
		}

		std::cout << std::get<0>(cmd);
		if (send(sockfd, std::get<0>(cmd).c_str(), std::get<0>(cmd).size(), 0) < 0) {
			close(sockfd);
			throw std::system_error { errno, std::system_category() };
		}

		char buffer[1024];
		int numbytes = recv(sockfd, buffer, 1024, 0);
		if (numbytes < 0) {
			close(sockfd);
			throw std::system_error { errno, std::system_category() };
		}
		buffer[numbytes] = '\0';
		std::cout << buffer << std::endl << std::endl;

		std::cout << std::get<1>(cmd);
		if (send(sockfd, std::get<1>(cmd).c_str(), std::get<1>(cmd).size(), 0) < 0) {
			close(sockfd);
			throw std::system_error { errno, std::system_category() };
		}

		numbytes = recv(sockfd, buffer, 1024, 0);
		if (numbytes < 0) {
			close(sockfd);
			throw std::system_error { errno, std::system_category() };
		}
		buffer[numbytes] = '\0';
		std::cout << buffer << std::endl << std::endl;

		close(sockfd);
	}
}
