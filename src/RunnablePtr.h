/*
 * RunnablePtr.h
 *
 *  Created on: 2017年8月20日
 *      Author: marsnowxiao
 */

#include <stddef.h>
#include "_Runnable.h"

class RunnablePtr
{
public:
    RunnablePtr(Runnable* obj = NULL): ptr(obj)
    {
        init();
    }
    RunnablePtr(RunnablePtr const& rhs): ptr(rhs.ptr)
    {
        init();
    }
    RunnablePtr& operator=(RunnablePtr const& rhs)
    {
        if (ptr == rhs.ptr) {
            return *this;
        }
        Runnable* oldptr = ptr;
        ptr = rhs.ptr;
        init();
        if (oldptr != NULL) {
            oldptr->decRefCount();
        }
        return *this;
    }
    ~RunnablePtr()
    {
        if(ptr) {
            ptr->decRefCount();
        }
    }
    Runnable* operator->() const
    {
        return ptr;
    }
    Runnable& operator*() const
    {
        return *ptr;
    }
    bool operator==(RunnablePtr const& rhs) const
    {
        return (ptr == rhs.ptr);
    }
    bool operator!=(RunnablePtr const& rhs) const
    {
        return !(*this == rhs);
    }
private:
    Runnable* ptr;
    void init()
    {
        if (ptr == NULL)
            return;
        ptr->incRefCount();
    }
};
