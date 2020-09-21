#pragma once

#include"operatorID.hpp"

namespace server_side {

/**
 * @brief parse the given input from client to an OperatorID type.
 */
//since OperatorID is only an interface,
//PLEASE NOTE THIS: THIS FUNCTION ALLOCATES MEMORY AND RETURNS IT!
//YOU MUST BE IN CHARGE OF FREEING THIS MEMORY LATER WITH delete IF YOU CALL THIS FUNCTION!!!!!
//I know this isn't great, but it is the only way if you work with abstract classes and Interfaces.
OperatorID* parseToOperatorID(std::string content);

}
