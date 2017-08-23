/*
 * Runnable.cpp
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */

#include "_Thread.h"
#include "_Runnable.h"

Runnable::Runnable()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&lock, &attr);
	pthread_mutexattr_destroy(&attr);
	Thread::allThreads[pthread_self()]->addRunnablePtr(this);
}

Runnable::~Runnable()
{
	pthread_mutex_destroy(&lock);
}

void Runnable::destory()
{
	delete this;
}

void Runnable::synchronize_begin(Runnable *runnable)
{
	pthread_mutex_lock(&runnable->lock);
}

void Runnable::synchronize_end(Runnable *runnable)
{
	pthread_mutex_unlock(&runnable->lock);
}
