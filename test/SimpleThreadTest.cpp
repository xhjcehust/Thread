/*
 * SimpleThreadTest.cpp
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */
#include <iostream>
#include <unistd.h>
#include <Thread.h>

class SimpleThread: public Thread
{
public:
    virtual void run()
    {
    		Thread::run();
        std::cout << "I am a Thread\n";
        sleep(2);
    }
    ~SimpleThread()
    {
    		std::cout << "I can free myself\n";
    }
};

int main(int argc, char* argv[])
{
	SimpleThread *thread = new SimpleThread;
	thread->start();
	return 0;
}
