all: mytest

problem=problem_classes.cpp
CC=g++ -std=c++11 -g

mytest: mytest.cpp $(problem)
	$(CC) -o mytest mytest.cpp

clean:
	rm -f *.o *.out *.txt mytest 