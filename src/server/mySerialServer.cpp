#include"./mySerialServer.hpp"

#include<arpa/inet.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>

void MySerialServer::open(int port, ClientHandler const& c) {
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
	if (0 > connect(sockfd, reinterpret_cast<const sockaddr*>(&connectAddress),
	                sizeof(connectAddress))) {
		close(sockfd);
		throw std::system_error { errno, std::system_category() };
	}
	std::string buffer(1024, '\0');
	const auto numBytesRead = read(sockfd, buffer.data(), buffer.size() - 1);
	if (numBytesRead < 0) {
		close(sockfd);
		throw std::system_error { errno, std::system_category() };
	}
	buffer[numBytesRead] = '\0';

	if (write(sockfd, "hello, world!", 13) < 0) {
		close(sockfd);
		throw std::system_error { errno, std::system_category() };
	}
}
void stop() {
}
