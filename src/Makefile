CPP =	g++
CFLAGS =  -O -Wall -Wextra -Wpointer-arith -Wconditional-uninitialized -Wno-unused-parameter -Wno-deprecated-declarations -Werror -g 
HEADERS = Exception/BaseException.h\
	Exception/IllegalArgumentException.h\
	Exception/IllegalThreadStateException.h\
	Exception/ThreadCreateFailedException.h

Thread.a: Thread.o Runnable.o ThreadEntry.o
	ar -r Thread.a Thread.o Runnable.o ThreadEntry.o
	
Thread.o: Thread.cpp _Thread.h UnCopyable.h RunnablePtr.h $(HEADERS)
	$(CPP) -c $(CFLAGS) -o Thread.o Thread.cpp
Runnable.o: Runnable.cpp _Runnable.h RefCountable.h
	$(CPP) -c $(CFLAGS) -o Runnable.o Runnable.cpp
ThreadEntry.o: ThreadEntry.cpp ThreadEntry.h _Thread.h
	$(CPP) -c $(CFLAGS) -o ThreadEntry.o ThreadEntry.cpp

clean:
	-rm -rf *.so *.o *.a

.PHONY:clean
	