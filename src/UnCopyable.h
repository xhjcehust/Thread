/*
 * Uncopyable.h
 *
 *  Created on: 2017年8月20日
 *      Author: marsnowxiao
 */

#ifndef UNCOPYABLE_H_
#define UNCOPYABLE_H_

class UnCopyable
{
public:
	UnCopyable() {}
	~UnCopyable() {}
private:
	UnCopyable(const UnCopyable&);
	UnCopyable& operator=(const UnCopyable&);
};

#endif /* UNCOPYABLE_H_ */
