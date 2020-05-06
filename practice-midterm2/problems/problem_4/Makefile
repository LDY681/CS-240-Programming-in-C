all: mytest

mytest: mytest.c problem_convert.c
	gcc -std=gnu99 -g -o mytest mytest.c problem_convert.c

clean:
	rm -f *.o *.out *.txt mytest
