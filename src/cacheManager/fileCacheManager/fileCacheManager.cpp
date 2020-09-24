#include"fileCacheManager.hpp"
#include<string>
#include<fstream>
#include"../../operatorID/operatorID.hpp"

namespace server_side {

FileCacheManager::FileCacheManager(std::string const& workPlace) : m_folderManager(workPlace) { }

bool FileCacheManager::isInCache(OperatorID const& id) const {
	return m_folderManager.fileExists(id.hash());
}
void FileCacheManager::addOp(OperatorID const& id, std::string const& result) {
	m_folderManager.add(id.hash(), result);
}
std::string FileCacheManager::getResult(OperatorID const& id) const {
	std::ifstream is {workPlace() +"/"+ id.hash()};
	return std::string {(std::istreambuf_iterator<char>(is)), std::istreambuf_iterator<char>()};
}
std::string FileCacheManager::workPlace() const {
	return m_folderManager.folderPath();
}

void FileCacheManager::save() const {
	m_folderManager.save();
}

}
