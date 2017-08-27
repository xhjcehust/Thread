/*
 * _Runnable.h
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */

#ifndef _RUNNABLE_H_
#define _RUNNABLE_H_

#include <pthread.h>
#include "UnCopyable.h"
#include "RefCountable.h"
#include "Lock.h"

class Runnable: private UnCopyable, public RefCountable, public Lock
{
public:
    Runnable();
    virtual void run() = 0;
    void destory();
protected:
    virtual ~Runnable() = 0;
};


#endif /* _RUNNABLE_H_ */
