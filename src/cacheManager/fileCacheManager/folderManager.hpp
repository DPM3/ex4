#pragma once

#include<string>
#include<vector>

namespace server_side {

class FolderManager {
public:
	static constexpr int s_maxSize = 69; //NICE
private:
	std::string m_folderPath;
	std::string m_files[s_maxSize];

	class Marker {
		int m_index;
	public:
		Marker& operator++();
		Marker operator++(int);
		Marker& operator--();
		Marker operator--(int);
		operator int() const;
		int& index();
	};
	Marker m_marker;

public:
	/**
	 * @brief default constructor
	 */
	FolderManager() = default;

	/**
     * @brief real constructor
     *
     * @param[in] pathToDir. path to directory (work place)
     */
	FolderManager(std::string const& pathToDir);

	/**
     * @brief add file to cache
     *
     * @param[in] fileName. the name of the file
     * @param[in] fileSource. the file's result
     */
	void add(std::string const& fileName, std::string const& fileSource); //takes care of removing from cache last file

	/**
     * @brief checks if file exists
     *
     * @param[in] fileName. name of the file
     * @return boolean
     */
	bool fileExists(std::string const& fileName) const;

	/**
     * @brief clears folder manager
     */
	void clear();

	/**
     * @brief save
     */
	void save() const;

	/**
     * @brief returns path to folder
     *
     * @return string
     */
	std::string folderPath() const;
private:
	/**
     * @brief removes file (help for add function)
     *
     * @param[in] fileName. name of file
     */
	void remove(std::string const& fileName);
};

}
