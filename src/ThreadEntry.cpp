/*
 * ThreadEntry.cpp
 *
 *  Created on: 2017年8月19日
 *      Author: marsnowxiao
 */
#include "ThreadEntry.h"
#include "_Thread.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
	int ret = __Main(argc, argv);
	Thread::waitAll();
	return ret;
}
