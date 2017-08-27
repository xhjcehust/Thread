/*
 * ThreadCreateFailedException.h
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */

#ifndef THREADCREATEFAILEDEXCEPTION_H_
#define THREADCREATEFAILEDEXCEPTION_H_

#include "BaseException.h"

class ThreadCreateFailedException: public BaseException
{
public:
    ThreadCreateFailedException(std::string message = "", int code = 0):
        BaseException(message, code)
    {}
};


#endif /* THREADCREATEFAILEDEXCEPTION_H_ */
