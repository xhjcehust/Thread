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

class Runnable: private UnCopyable, public RefCountable
{
public:
	Runnable();
	virtual void run() = 0;
	void destory();
	static void synchronize_begin(Runnable *runnable);
	static void synchronize_end(Runnable *runnable);
protected:
	pthread_mutex_t lock;
	virtual ~Runnable() = 0;
};


#endif /* _RUNNABLE_H_ */
