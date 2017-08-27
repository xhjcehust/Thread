/*
 * SyncTest.cpp
 *
 *  Created on: 2017年8月21日
 *      Author: marsnowxiao
 */

#include <iostream>
#include <Thread.h>

class SyncRunnable: public Runnable
{
public:
    SyncRunnable()
    {
        m = 0;
    }
    virtual void run()
    {
        synchronize_begin(this);
        for (int i = 0 ; i < 100; i++) {
            Thread::currentThread()->getName();
            std::cout << Thread::currentThread()->getName() << " " << m++ << std::endl;
        }
        synchronize_end(this);
    }
protected:
    virtual ~SyncRunnable()
    {
        std::cout << "free runnable" << std::endl;
    }
private:
    int m;
};

int main(int argc, char* argv[])
{
    Runnable *runnable = new SyncRunnable();
    Thread *thread = new Thread(runnable);
    thread->start();

    thread = new Thread(runnable);
    thread->start();
    return 0;
}
