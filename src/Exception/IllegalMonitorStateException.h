/*
 * IllegalMonitorStateException.h
 *
 *  Created on: 2017年8月27日
 *      Author: marsnowxiao
 */

#ifndef ILLEGALMONITORSTATEEXCEPTION_H_
#define ILLEGALMONITORSTATEEXCEPTION_H_

#include "BaseException.h"

class IllegalMonitorStateException: public BaseException
{
public:
	IllegalMonitorStateException(std::string message = "", int code = 0):
			BaseException(message, code)
	{}
};


#endif /* ILLEGALMONITORSTATEEXCEPTION_H_ */
