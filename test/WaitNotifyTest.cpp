/*
 * WaitNotifyTest.cpp
 *
 *  Created on: 2017年8月27日
 *      Author: marsnowxiao
 */

#include <iostream>
#include <unistd.h>
#include <Thread.h>

class WaitThread: public Thread
{
public:
    WaitThread(Lock *lock, int *ptr): Thread()
    {
        this->lock = lock;
        this->ptr = ptr;
    }
    void run()
    {
        synchronize_begin(lock);
        std::cout << Thread::currentThread()->getName() << " begin to wait" << std::endl;
        while (*ptr < 5) {
            lock->wait();
        }
        std::cout << Thread::currentThread()->getName() << " wake up" << std::endl;
        synchronize_end(lock);
    }
private:
    Lock *lock;
    int *ptr;
};

class NotifyThread: public Thread
{
public:
    NotifyThread(Lock *lock, int *ptr)
    {
        this->lock = lock;
        this->ptr = ptr;
    }
    void run()
    {
        synchronize_begin(lock);
        for (int i = 0; i < 10; i++) {
            (*ptr)++;
            std::cout << "value = " << (*ptr) << std::endl;
            if (*ptr == 5) {
                lock->notify();
            }
            sleep(1);
        }
        synchronize_end(lock);
    }
private:
    Lock *lock;
    int *ptr;
};

int main(int argc, char* argv[])
{
    Lock lock;
    int value = 0;
    Thread *waitT = new WaitThread(&lock, &value);
    waitT->start();

    Thread *notifyT = new NotifyThread(&lock, &value);
    notifyT->start();

    waitT->join();
    notifyT->join();
    return 0;
}
