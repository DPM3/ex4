#pragma once

#include<string>

struct OperatorID {
	/**
	 * @brief returns an operator's hash code value
	 *
	 * @param[in] op. operator's info
	 * @return string
	 */
	virtual std::string hash() const = 0;
};
