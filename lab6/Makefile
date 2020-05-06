
all: test_linked_list ptr-simple simple_list

ptr-simple: ptr-simple.c 
	gcc -std=gnu99 -g -o ptr-simple ptr-simple.c

simple_list: simple_list.c 
	gcc -std=gnu99 -g -o simple_list simple_list.c

test_linked_list: LinkedList.c test_linked_list.c
	gcc -std=gnu99 -g -o test_linked_list test_linked_list.c LinkedList.c

org: 
	cp test_linked_list test_linked_list.org

clean:
	rm -f *.o *.out total.txt grades1.rt test_linked_list ptr-simple simple_list

