/*
 * _Thread.h
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */

#ifndef _THREAD_H_
#define _THREAD_H_

#include <string>
#include <map>
#include <pthread.h>
#include "_Runnable.h"
#include "RunnablePtr.h"

class Thread: public Runnable
{
public:
	Thread();
	Thread(const std::string &name);
	Thread(RunnablePtr runnable);
	std::string getName() const;
	void setName(const std::string &name);
	pthread_t getId();
	int getPriority();
	void setPriority(int priority);
	int getPolicy();
	void setPolicy(int policy);
	virtual void run();
	void start();
	static void waitAll();
	static const Thread* currentThread();

	/* Store all Threads information, tid => pointer to thread instance */
	static std::map<pthread_t, Thread*> allThreads;
protected:
	virtual ~Thread();
private:
	std::string name;
	int policy;
	sched_param param;
	bool started;
	pthread_t tid;
	pthread_attr_t attr;
	/* What will be run. */
	RunnablePtr target;
	/* For autonumbering anonymous threads. */
	static int threadInitNumber;

	class StaticBlock
	{
	public:
		StaticBlock()
		{
			mainThread = new Thread("main");
			Thread::allThreads[pthread_self()] = mainThread;
		}
		~StaticBlock()
		{
			delete mainThread;
		}
	private:
		Thread *mainThread;
	};
	static StaticBlock block;
	void init(RunnablePtr target, const std::string &name);
	static int nextThreadNum();
	static void *routine(void *args);
};

#endif /* _THREAD_H_ */
