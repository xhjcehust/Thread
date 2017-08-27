CPP =	g++
CFLAGS =  -O -Wall -Werror -g 
HEADERS = Exception/BaseException.h\
	Exception/IllegalArgumentException.h\
	Exception/IllegalThreadStateException.h\
	Exception/ThreadCreateFailedException.h\
	Exception/IllegalMonitorStateException.h

Thread.a: Thread.o Runnable.o ThreadEntry.o Lock.o
	ar -r Thread.a Thread.o Runnable.o ThreadEntry.o Lock.o
	
Thread.o: Thread.cpp _Thread.h UnCopyable.h RunnablePtr.h $(HEADERS)
	$(CPP) -c $(CFLAGS) -o Thread.o Thread.cpp
	
Runnable.o: Runnable.cpp _Runnable.h RefCountable.h
	$(CPP) -c $(CFLAGS) -o Runnable.o Runnable.cpp
	
ThreadEntry.o: ThreadEntry.cpp ThreadEntry.h _Thread.h
	$(CPP) -c $(CFLAGS) -o ThreadEntry.o ThreadEntry.cpp

Lock.o: Lock.cpp Lock.h
	$(CPP) -c $(CFLAGS) -o Lock.o Lock.cpp

clean:
	-rm -rf *.so *.o *.a

.PHONY:clean
	