/*
 * Lock.cpp
 *
 *  Created on: 2017年8月27日
 *      Author: marsnowxiao
 */

#include <string.h>
#include "_Runnable.h"
#include "Exception/IllegalMonitorStateException.h"

Lock::Lock()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&lock, &attr);
	pthread_mutexattr_destroy(&attr);

	memset(&lockOwnerTid, 0, sizeof(lockOwnerTid));

	pthread_cond_init(&cond, NULL);
}

void Lock::synchronize_begin(Lock *lock)
{
	pthread_mutex_lock(&lock->lock);
	lock->lockOwnerTid = pthread_self();
}

void Lock::synchronize_end(Lock *lock)
{
	pthread_mutex_unlock(&lock->lock);
	memset(&lock->lockOwnerTid, 0, sizeof(lock->lockOwnerTid));
}

void Lock::wait()
{
	if (lockOwnerTid != pthread_self()) {
		throw new IllegalMonitorStateException();
	}
	pthread_cond_wait(&cond, &lock);
}

void Lock::notify()
{
	if (lockOwnerTid != pthread_self()) {
		throw new IllegalMonitorStateException();
	}
	pthread_cond_signal(&cond);
}

void Lock::notifyAll()
{
	if (lockOwnerTid != pthread_self()) {
		throw new IllegalMonitorStateException();
	}
	pthread_cond_broadcast(&cond);
}
