#include"operatorID.hpp"

/* //old...
std::string hash(OperatorID op) {
	std::ifstream ifs, ifs2;
	std::string content = "";
	std::string hash, hash2;
	switch (op.type) {
		case OperatorID::MAT_ADD:
			ifs = std::ifstream(op.operands[0]);
			content += std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());

			ifs2 = std::ifstream(op.operands[1]);
			content += std::string((std::istreambuf_iterator<char>(ifs2)), std::istreambuf_iterator<char>());

			hash = sha1(content);

			content = "";
			content += std::string((std::istreambuf_iterator<char>(ifs2)), std::istreambuf_iterator<char>());
			content += std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
			hash2 = sha1(content);
//			std::cout << "hash of mat add: " << (std::strcmp(hash.c_str(), hash2.c_str()) == 1 ? hash : hash2) << std::endl;

			return std::strcmp(hash.c_str(), hash2.c_str()) == 1 ? hash : hash2;

		case OperatorID::MAT_MULT:
			ifs = std::ifstream(op.operands[0]);
			content += std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
			ifs2 = std::ifstream(op.operands[1]);
			content += std::string((std::istreambuf_iterator<char>(ifs2)), std::istreambuf_iterator<char>());
			return sha1(content);

		case OperatorID::IMG_ROT:
		case OperatorID::IMG_GS:
		case OperatorID::HS_CRC32:
			ifs = std::ifstream(op.operands[0]);
			content += std::string((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
			return sha1(content + std::string{ (char)(op.type + 1) } );
			break;

		default: return "kzlx;dgkilshjdfg;";
	}
}
*/ //old stuff..
