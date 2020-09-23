#include"./mySerialServer.hpp"

#include<arpa/inet.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<thread>
#include<sstream>

namespace server_side {

void MySerialServer::open(int port, ClientHandler const& c) {
	const int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		throw std::system_error { errno, std::system_category() };
	}
	int True = 1;
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &True, sizeof(int));

	sockaddr_in connectAddress{};
	if (0 == inet_aton("127.0.0.1", &connectAddress.sin_addr)) {
		close(sockfd);
		throw std::runtime_error{"Failed converting IP to 4-bytes"};
	}
	connectAddress.sin_family = AF_INET;
	connectAddress.sin_port = htons(port);
	if (bind(sockfd, reinterpret_cast<const sockaddr*>(&connectAddress), sizeof(connectAddress)) < 0) {
		std::cout << "send\n";
		close(sockfd);
		throw std::system_error { errno, std::system_category() };
	}

	if (listen(sockfd, 150) < 0) {
		close(sockfd);
		throw std::system_error { errno, std::system_category() };
	}

	std::thread serverAction {[=, &c]() {
		int connectAddresslen = sizeof(connectAddress);
		while (m_stop) {
			int connectionfd = accept(sockfd, (struct sockaddr*)&connectAddress, (socklen_t*)&connectAddresslen);
			if (connectionfd < 0) {
				throw std::system_error { errno, std::system_category() };
			}
			std::thread clientTalk {[=, &c]() {
				for(int i = 0; i < 2; ++i) {
					char buffer[1024];
					int recvLength = recv(connectionfd, buffer, 1024, 0);
					if (recvLength < 0) {
						close(connectionfd);
						close(sockfd);
						throw std::system_error { errno, std::system_category() };
					}
					buffer[recvLength] = '\0';

					std::stringstream is;
					is << buffer;
					std::stringstream os;

					c.handleClient(is, os);

					std::string s = os.str();
					if (send(connectionfd, s.c_str(), s.size(), 0) < 0) {
						close(connectionfd);
						close(sockfd);
						throw std::system_error { errno, std::system_category() };
					}
				}
				close(connectionfd);
			}};
			clientTalk.detach();
		}
		close(sockfd);
	}};
	serverAction.detach();
}
void MySerialServer::stop() {
	m_stop = true;
}

}
