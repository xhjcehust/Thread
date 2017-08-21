/*
 * SimpleThreadTest.cpp
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */
#include <iostream>
#include <Thread.h>

class SimpleThread: public Thread
{
public:
	SimpleThread(): Thread()
    	{}
	SimpleThread(Runnable *runnable): Thread(runnable)
    {}
    virtual void run()
    {
    		Thread::run();
        std::cout << "SimpleThread\n";
    }
    ~SimpleThread()
    {
    		std::cout << "~SimpleThread\n";
    }
};

int main(int argc, char* argv[])
{
	SimpleThread *thread = new SimpleThread;
	thread->start();
	thread = new SimpleThread;
	thread->start();
	return 0;
}
