/*
 * IllegalThreadStateException.h
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */

#ifndef ILLEGALTHREADSTATEEXCEPTION_H_
#define ILLEGALTHREADSTATEEXCEPTION_H_

#include "BaseException.h"

class IllegalThreadStateException: public BaseException
{
public:
	IllegalThreadStateException(std::string message = "", int code = 0):
			BaseException(message, code)
	{}
};


#endif /* ILLEGALTHREADSTATEEXCEPTION_H_ */
