/*
 * BaseException.h
 *
 *  Created on: 2017年8月20日
 *      Author: marsnowxiao
 */

#ifndef BASEEXCEPTION_H_
#define BASEEXCEPTION_H_

#include <string>

class BaseException
{
public:
	BaseException(std::string message = "", int code = 0):
		message(message), code(code)
	{}
	std::string getMessage()
	{
		return message;
	}
	int getCode()
	{
		return code;
	}
	~BaseException()
	{}
private:
	std::string message;
	int code;
};


#endif /* BASEEXCEPTION_H_ */
