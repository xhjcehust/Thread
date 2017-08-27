/*
 * SimpleRunnableTest.cpp
 *
 *  Created on: 2017年8月20日
 *      Author: marsnowxiao
 */

#include <iostream>
#include <unistd.h>
#include <Thread.h>

class SimpleRunnable: public Runnable
{
public:
    virtual void run()
    {
    		std::cout << "SimpleRunnable" << std::endl;
    		sleep(2);
    }
    ~SimpleRunnable()
	{
		std::cout << "I can free myself\n";
	}
};

int main(int argc, char* argv[])
{
	Runnable *runnable = new SimpleRunnable();
	Thread *thread = new Thread(runnable);
	thread->start();

	return 0;
}
