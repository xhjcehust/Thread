/*
 * Lock.h
 *
 *  Created on: 2017年8月27日
 *      Author: marsnowxiao
 */

#ifndef LOCK_H_
#define LOCK_H_

class Lock
{
public:
	Lock();
	static void synchronize_begin(Lock *lock);
	static void synchronize_end(Lock *lock);
	void wait();
	void notify();
	void notifyAll();
protected:
	pthread_mutex_t lock;
	pthread_cond_t cond;
	pthread_t lockOwnerTid;
};

#endif /* LOCK_H_ */
