#include"fileCacheManager.hpp"
#include<string>
#include<fstream>
#include"../../operatorID/operatorID.hpp"

namespace server_side {

FileCacheManager::FileCacheManager(std::string const& workPlace) : m_folderManager(workPlace) { }

bool FileCacheManager::isInCache(OperatorID const& id) {
	return m_folderManager.fileExists(id.hash());
}
void FileCacheManager::addOp(OperatorID const& id, std::string const& resultPath) {
	m_folderManager.add(id.hash(), resultPath);
}
std::string FileCacheManager::getResult(OperatorID const& id) {
	std::ifstream is {workPlace() +"/"+ id.hash()};
	std::string content {(std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>()};
	return content;
}
std::string FileCacheManager::workPlace() {
	return m_folderManager.folderPath();
}

void FileCacheManager::save() {
	m_folderManager.save();
}

}
