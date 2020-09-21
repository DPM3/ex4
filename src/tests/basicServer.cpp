#include<iostream>
#include<thread>
#include<arpa/inet.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include"../server/mySerialServer.hpp"
#include"../clientHandler/myTestClientHandler.hpp"

int main() {
	const int port = 8082;

	server_side::MySerialServer mss;
	mss.open(port, server_side::MyTestClientHandler{});

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

	std::string input = "hello";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	if (send(sockfd, input.c_str(), input.size(), 0) < 0) {
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
	std::cout << buffer << std::endl;
	close(sockfd);
}
