CPP =	g++
CFLAGS =  -O -Wall -Wextra -Wpointer-arith -Wconditional-uninitialized -Wno-unused-parameter -Wno-deprecated-declarations -Werror -g 
LIBS = ../src/Thread.a
INCS = -I ../src

all:SimpleThreadTest RunnableTest


SimpleThreadTest: SimpleThreadTest.o $(LIBS)
	$(CPP) $(INCS)  -o SimpleThreadTest SimpleThreadTest.o $(LIBS) -lpthread

SimpleThreadTest.o: SimpleThreadTest.cpp
	$(CPP) $(INCS) -c $(CFLAGS)  -o SimpleThreadTest.o SimpleThreadTest.cpp

RunnableTest: RunnableTest.o $(LIBS)
	$(CPP) $(INCS) -o RunnableTest RunnableTest.o $(LIBS) -lpthread
	
RunnableTest.o: RunnableTest.cpp
	$(CPP) $(INCS)  -c $(CFLAGS)  -o RunnableTest.o RunnableTest.cpp
	
clean:
	-rm -rf SimpleThreadTest RunnableTest *.o

.PHONY: clean