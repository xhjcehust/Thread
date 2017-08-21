/*
 * RefCountable.h
 *
 *  Created on: 2017年8月21日
 *      Author: marsnowxiao
 */

#ifndef REFCOUNTABLE_H_
#define REFCOUNTABLE_H_

class RefCountable
{
public:
	RefCountable(): refCount(0)
	{}
	RefCountable(const RefCountable& rhs) : refCount(rhs.refCount)
	{}
	RefCountable& operator=(const RefCountable& rhs)
	{
		return *this;
	}
	virtual ~RefCountable()
	{}
	void incRefCount()
	{
		__sync_fetch_and_add(&refCount, 1);
	}
	void decRefCount()
	{
		if (__sync_sub_and_fetch(&refCount, 1) == 0) {
			delete this;
		}
	}
private:
	unsigned long refCount;
};


#endif /* REFCOUNTABLE_H_ */
