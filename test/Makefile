CPP =	g++
CFLAGS =  -O -Wall -Werror -g 
LIBS = ../src/Thread.a
INCS = -I ../src

all:SimpleThreadTest SimpleRunnableTest SyncTest WaitNotifyTest


SimpleThreadTest: SimpleThreadTest.o $(LIBS)
	$(CPP) $(INCS)  -o SimpleThreadTest SimpleThreadTest.o $(LIBS) -lpthread

SimpleThreadTest.o: SimpleThreadTest.cpp
	$(CPP) $(INCS) -c $(CFLAGS)  -o SimpleThreadTest.o SimpleThreadTest.cpp

SimpleRunnableTest: SimpleRunnableTest.o $(LIBS)
	$(CPP) $(INCS) -o SimpleRunnableTest SimpleRunnableTest.o $(LIBS) -lpthread
	
SimpleRunnableTest.o: SimpleRunnableTest.cpp
	$(CPP) $(INCS)  -c $(CFLAGS)  -o SimpleRunnableTest.o SimpleRunnableTest.cpp

SyncTest: SyncTest.o $(LIBS)
	$(CPP) $(INCS) -o SyncTest SyncTest.o $(LIBS) -lpthread
	
SyncTest.o: SyncTest.cpp
	$(CPP) $(INCS)  -c $(CFLAGS)  -o SyncTest.o SyncTest.cpp
	
WaitNotifyTest: WaitNotifyTest.o $(LIBS)
	$(CPP) $(INCS) -o WaitNotifyTest WaitNotifyTest.o $(LIBS) -lpthread
	
WaitNotifyTest.o: WaitNotifyTest.cpp
	$(CPP) $(INCS)  -c $(CFLAGS)  -o WaitNotifyTest.o WaitNotifyTest.cpp
	
clean:
	-rm -rf SimpleThreadTest SimpleRunnableTest SyncTest *.o

.PHONY: clean