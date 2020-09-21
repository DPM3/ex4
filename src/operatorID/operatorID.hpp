#pragma once

#include<string>

namespace server_side {

struct OperatorID {
	/**
	 * @brief returns an operator's hash code value
	 *
	 * @param[in] op. operator's info
	 * @return string
	 */
	virtual std::string hash() const = 0;
};

}
