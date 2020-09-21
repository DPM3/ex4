#pragma once
#include<string>

namespace server_side {

/**
 * @brief returns a string's sha1 hash code
 *
 * @param[in] content. the string
 * @return string
 */
std::string sha1(std::string const& content);

}
