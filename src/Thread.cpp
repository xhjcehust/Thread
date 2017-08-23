/*
 * Thread.cpp
 *
 *  Created on: 2017年8月18日
 *      Author: marsnowxiao
 */

#include <sstream>
#include <sched.h>
#include "_Thread.h"
#include "Exception/IllegalThreadStateException.h"
#include "Exception/IllegalArgumentException.h"
#include "Exception/ThreadCreateFailedException.h"
#include <iostream>

Thread::Thread()
{
	std::ostringstream os;
	os << nextThreadNum();
	init(NULL, "Thread-" + os.str());
}

Thread::Thread(const std::string &name)
{
	init(NULL, name);
}

Thread::Thread(RunnablePtr target)
{
	std::ostringstream os;
	os << nextThreadNum();
	init(target, "Thread-" + os.str());
}

int Thread::nextThreadNum()
{
	return threadInitNumber++;
}

void Thread::run()
{
	if (target != NULL) {
		target->run();
	}
}

void Thread::start()
{
	if (this->started) {
		throw new IllegalThreadStateException("Thread has been started");
	}
	pthread_attr_init(&attr);
	pthread_attr_setschedpolicy(&attr, policy);
	pthread_attr_setschedparam(&attr, &param);
	if (0 != pthread_create(&tid, &attr, &routine, this)) {
		throw new ThreadCreateFailedException("pthread_create failed");
	}
	allThreads[tid] = this;
	this->started = true;
}

void *Thread::routine(void *args)
{
	RunnablePtr runnable = (Thread *)args;
	try {
		runnable->run();
	} catch (...) {

	}
	return NULL;
}

void Thread::init(RunnablePtr target, const std::string &name)
{
	this->started = false;
	this->target = target;
	this->name = name;
	pthread_getschedparam(pthread_self(), &this->policy, &this->param);
}

std::string Thread::getName() const
{
	return name;
}

void Thread::setName(const std::string &name)
{
	this->name = name;
}

int Thread::getPriority()
{
	return this->param.sched_priority;
}

void Thread::setPriority(int priority)
{
	int maxPriority = sched_get_priority_max(policy);
	int minPriority = sched_get_priority_min(policy);
	if (priority > maxPriority || priority < minPriority) {
		throw new IllegalArgumentException("invalid priority");
	}
	this->param.sched_priority = priority;
}

int Thread::getPolicy()
{
	return this->policy;
}

void Thread::setPolicy(int policy)
{
	this->policy = policy;
}

pthread_t Thread::getId()
{
	return tid;
}

const Thread* Thread::currentThread()
{
	return allThreads.at(pthread_self());
}

void Thread::waitAll()
{
	pthread_t tid = pthread_self();
	for(std::map<pthread_t, Thread*>::iterator iter = Thread::allThreads.begin();
				iter != Thread::allThreads.end(); iter++) {

		if (iter->first != tid) {
			pthread_join(iter->first, NULL);
		}
	}
}

void Thread::addRunnablePtr(const RunnablePtr& runnable)
{
	runnables.push_back(runnable);
}

Thread::~Thread()
{

}

int Thread::threadInitNumber = 0;
std::map<pthread_t, Thread*> Thread::allThreads;
Thread::StaticBlock Thread::block;
