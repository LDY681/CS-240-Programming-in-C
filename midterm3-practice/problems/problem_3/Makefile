CXX = g++ -g -std=c++11

all: mytest

mytest: mytest.cpp problem_dllist.cpp DLList.h
	$(CXX) -o mytest mytest.cpp problem_dllist.cpp

clean:
	rm -f *.o *.out *.txt mytest 
