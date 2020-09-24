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
	virtual std::string solve() const = 0;
	virtual ~OperatorID() = 0;
};

OperatorID::~OperatorID() { }

}
