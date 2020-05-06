CC=gcc
OPT=Wall
FLAGS=$(addprefix -, $(OPT))
DEBUG=-g
PROG=STR-2-3-0

all: mytest

# makes the test executable with the students solution
mytest: $(PROG).o $(PROG)-test.c
	$(CC) $(DEBUG) $(FLAGS) $(PROG).o $(PROG)-test.c -o mytest

# compiles the students solution
$(PROG).o: $(PROG).c
	$(CC) $(DEBUG) $(FLAGS) -c $(PROG).c -o $(PROG).o

# makes the test executable with the instructor solution
mytest.org: $(PROG)-sol.o $(PROG)-test.c
	$(CC) $(FLAGS) $(PROG)-sol.o $(PROG)-test.c -o mytest.org

# compiles the instructors solution
$(PROG)sol.o: $(PROG)-sol.c
	$(CC) $(FLAGS) -c $(PROG)-sol.c -o $(PROG)-sol.o

clean:
	rm *.o *.out none total.txt mytest
