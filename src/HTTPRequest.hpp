#ifndef SRC_HTTPREQUEST_HPP_
#define SRC_HTTPREQUEST_HPP_

#include <Arduino.h>
#include <string>

#include <mbedtls/base64.h>

#include "ConnectionContext.hpp"
#include "HTTPHeader.hpp"
#include "HTTPHeaders.hpp"
#include "ResourceParameters.hpp"
#include "util.hpp"

namespace httpsserver {

class HTTPRequest {
public:
	HTTPRequest(ConnectionContext * con, HTTPHeaders * headers, ResourceParameters * resource, std::string requestString, std::string method);
	virtual ~HTTPRequest();

	std::string getHeader(std::string name);
	void setHeader(std::string name, std::string value);
	std::string getRequestString();
	std::string getMethod();

	size_t readChars(char * buffer, size_t length);
	size_t readBytes(byte * buffer, size_t length);
	size_t getContentLength();
	bool   requestComplete();
	void   discardRequestBody();
	ResourceParameters * getParams();
	std::string getBasicAuthUser();
	std::string getBasicAuthPassword();
	bool   isSecure();
private:
	std::string decodeBasicAuthToken();

	ConnectionContext * _con;

	HTTPHeaders * _headers;

	ResourceParameters * _params;

	std::string _requestString;
	std::string _method;

	bool _contentLengthSet;
	size_t _remainingContent;
};

} /* namespace httpsserver */

#endif /* SRC_HTTPREQUEST_HPP_ */
