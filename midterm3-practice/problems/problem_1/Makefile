all: mytest

problem=problem_review.c
GCC=gcc -std=gnu99 -g

mytest: mytest.c $(problem)
	$(GCC) -o mytest mytest.c $(problem)

clean:
	rm -f *.o *.out *.txt mytest 
