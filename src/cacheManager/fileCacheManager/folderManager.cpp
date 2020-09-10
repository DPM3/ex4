#include"folderManager.hpp"

#include<string>
#include<fstream>
#include<filesystem>
#include<exception>
#include<iostream>

FolderManager::Marker& FolderManager::Marker::operator++() {
	++m_index;
	m_index -= m_index >= s_maxSize ? s_maxSize : 0;
	return *this;
}
FolderManager::Marker FolderManager::Marker::operator++(int) {
	Marker result = *this;
	++(*this);
	return result;
}

FolderManager::Marker& FolderManager::Marker::operator--() {
	--m_index;
	m_index += m_index < 0 ? s_maxSize : 0;
	return *this;
}
FolderManager::Marker FolderManager::Marker::operator--(int) {
	Marker result = *this;
	--(*this);
	return result;
}

FolderManager::Marker::operator int() {
	return m_index;
}

int& FolderManager::Marker::index() {
	return m_index;
}

FolderManager::FolderManager(std::string const& stateFilePath) : m_folderPath(stateFilePath), m_marker() {
	if (!std::filesystem::is_directory(stateFilePath)) {
		std::filesystem::create_directory(stateFilePath);
		return;
	}
	if (std::filesystem::exists(stateFilePath + "/STATE")) {
		std::ifstream stateFile{stateFilePath + "/STATE"};
		if (!stateFile) {
			throw std::runtime_error{"Coudn't open file: " + stateFilePath + "/STATE"};
		}
		for (std::string line; std::getline(stateFile, line); ) {
			m_files[m_marker++] = line;
		}
	}
}


void FolderManager::add(std::string const& fileName, std::string const& fileSource) {
	remove(m_files[++m_marker]);
	m_files[m_marker] = fileName;
	if (std::filesystem::exists(m_folderPath + "/" + fileName)) {
		std::filesystem::copy_file(fileSource, m_folderPath + "/" +  fileName, std::filesystem::copy_options::overwrite_existing);
	} else {
		std::filesystem::copy_file(fileSource, m_folderPath + "/" +  fileName);
	}
}

bool FolderManager::fileExists(std::string const& fileName) {
	for (auto fname : m_files) {
		if (fname == fileName) {
			return true;
		}
	}
	return false;
}
void FolderManager::clear() {
	for (auto& fname : m_files) {
		remove(fname);
		fname = "";
	}
	m_marker.index() = 0;
}

void FolderManager::save() {
	std::ofstream stateFile (m_folderPath + "/STATE");
	int startPoint = m_marker;
	do {
		stateFile << m_files[m_marker++] << std::endl;
	} while(m_marker != startPoint);
}

std::string FolderManager::folderPath() {
	return m_folderPath;
}

void FolderManager::remove(std::string const& fileName) {
	if (std::filesystem::exists(m_folderPath + fileName) &&
		!std::filesystem::is_directory(m_folderPath + fileName)) {
		std::filesystem::remove(m_folderPath + "/" + fileName);
	}
}
