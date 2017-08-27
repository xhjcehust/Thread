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
	/**
	 * Only When Main Thread is added into allThreads, start to manager
	 * all Runnable Objects
	 */
	if (Thread::allThreads.size() > 0) {
		Thread::allThreads[pthread_self()]->addRunnablePtr(this);
	}
}

Runnable::~Runnable()
{

}

void Runnable::destory()
{
	delete this;
}
