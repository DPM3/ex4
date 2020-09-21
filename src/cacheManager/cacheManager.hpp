#include"../operatorID/operatorID.hpp"
namespace server_side {

struct CacheManager {
	virtual bool isInCache(OperatorID const& op) = 0;
	virtual void addOp(OperatorID const& op, std::string const& resultPath) = 0;
	virtual std::string getFilename(OperatorID const& op) = 0;
};

}
