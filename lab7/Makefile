
all: git test_linked_list ptr-simple simple_list test_word_table

ptr-simple: ptr-simple.c 
	gcc -std=gnu99 -g -o ptr-simple ptr-simple.c

simple_list: simple_list.c 
	gcc -std=gnu99 -g -o simple_list simple_list.c

test_linked_list: LinkedList.c test_linked_list.c
	gcc -std=gnu99 -g -o test_linked_list test_linked_list.c LinkedList.c

test_word_table: test_word_table.c WordTable.c LinkedList.c
	gcc -std=gnu99 -g -o test_word_table test_word_table.c WordTable.c LinkedList.c

git:
	@#Do not remove or comment these lines. They are used for monitoring progress.
	@git add *.h *.c total.out >> local.git.out 2>&1 || echo
	@git total.out >> local.git.out 2>&1 || echo
	@git local.git.out >> local.git.out 2>&1 || echo
	git commit -a -m "Lab7" >> local.git.out 2>&1 || echo

clean:
	rm -f *.o *.out total.txt grades1.rt test_linked_list ptr-simple simple_list

