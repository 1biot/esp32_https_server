/*
 * HTTPHeaders.hpp
 *
 *  Created on: Dec 13, 2017
 *      Author: frank
 */

#ifndef SRC_HTTPHEADERS_HPP_
#define SRC_HTTPHEADERS_HPP_

#include <string>
// Arduino declares it's own min max, incompatible with the stl...
#undef min
#undef max
#include <vector>

#include "../src/HTTPSServerConstants.hpp"
#include "../src/HTTPHeader.hpp"

namespace httpsserver {

class HTTPHeaders {
public:
	HTTPHeaders();
	virtual ~HTTPHeaders();

	HTTPHeader * get(std::string name);
	void set(HTTPHeader * header);

	std::vector<HTTPHeader *> * getAll();

	void clearAll();

private:
	std::vector<HTTPHeader*> * _headers;
};

} /* namespace httpsserver */

#endif /* SRC_HTTPHEADERS_HPP_ */
