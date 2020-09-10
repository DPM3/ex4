#pragma once
#include<string>
#include"folderManager.hpp"
#include"../../operatorID/operatorID.hpp"
#include"../cacheManager.hpp"

class FileCacheManager : public CacheManager {
	FolderManager m_folderManager;
public:
	/**
     * @brief default constructor
     */
	FileCacheManager() = default;

	/**
     * @brief real constructor
     *
     * @param[in] workPlace. path to work place
     */
	FileCacheManager(std::string const& workPlace);

	/**
     * @brief checks if operation is in mini cache
     *
     * @param[in] id. operator's info
     * @return boolean
     */
	bool isInCache(OperatorID const& id) override;

	/**
     * @brief adds operation to mini cache
     *
     * @param[in] id. operation's info.
     * @param[in] resultPath. path to operation's result
     */
	void addOp(OperatorID const& id, std::string const& resultPath) override;

	/**
     * @brief returns file's name
     *
     * @param[in] id. operation's info
     * @return string
     */
	std::string getFileName(OperatorID const& id) override;

	/**
     * @brief returns mini cache's work place
     *
     * @return string
     */
	std::string workPlace();
	void save();
};
