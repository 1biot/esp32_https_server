/*
 * HTTPRequest.hpp
 *
 *  Created on: Dec 13, 2017
 *      Author: frank
 */

#ifndef HTTPS_HTTPREQUEST_HPP_
#define HTTPS_HTTPREQUEST_HPP_

#include <Arduino.h>
#include <string>

#include "util.hpp"

#include "ConnectionContext.hpp"
#include "HTTPHeaders.hpp"
#include "HTTPHeader.hpp"

namespace httpsserver {

class HTTPRequest {
public:
	HTTPRequest(ConnectionContext * con, HTTPHeaders * headers);
	virtual ~HTTPRequest();

	std::string getHeader(std::string name);

	size_t readChars(char * buffer, size_t length);
	size_t readBytes(byte * buffer, size_t length);
	size_t getContentLength();
	bool   requestComplete();
private:
	ConnectionContext * _con;

	HTTPHeaders * _headers;

	bool _contentLengthSet;
	size_t _remainingContent;
};

} /* namespace httpsserver */

#endif /* HTTPS_HTTPREQUEST_HPP_ */
