all: git test-mysort

test-mysort: test-mysort.c mysort.c
	gcc -std=gnu99 -g -o test-mysort test-mysort.c mysort.c

git:
	#Do not remove or comment these lines. They are used for monitoring progress.
	git add *.h *.c total.out >> local.git.out 2>&1 || echo
	git total.out >> local.git.out 2>&1 || echo
	git local.git.out >> local.git.out 2>&1 || echo
	git commit -a -m "Lab8" >> local.git.out 2>&1 || echo

clean:
	rm -f *.o *.out *.txt test test-mysort none
