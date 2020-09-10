#include"fileCacheManager.hpp"
#include<string>
#include"../../operatorID/operatorID.hpp"

FileCacheManager::FileCacheManager(std::string const& workPlace) : m_folderManager(workPlace) { }

bool FileCacheManager::isInCache(OperatorID const& id) {
	return m_folderManager.fileExists(id.hash());
}
void FileCacheManager::addOp(OperatorID const& id, std::string const& resultPath) {
	m_folderManager.add(id.hash(), resultPath);
}
std::string FileCacheManager::getFileName(OperatorID const& id) {
	return workPlace() +"/"+ id.hash();
}
std::string FileCacheManager::workPlace() {
	return m_folderManager.folderPath();
}

void FileCacheManager::save() {
	m_folderManager.save();
}
