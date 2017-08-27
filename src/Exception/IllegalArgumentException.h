/*
 * IllegalArgumentException.h
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */

#ifndef ILLEGALARGUMENTEXCEPTION_H_
#define ILLEGALARGUMENTEXCEPTION_H_

#include "BaseException.h"

class IllegalArgumentException: public BaseException
{
public:
    IllegalArgumentException(std::string message = "", int code = 0):
        BaseException(message, code)
    {}
};


#endif /* ILLEGALARGUMENTEXCEPTION_H_ */
