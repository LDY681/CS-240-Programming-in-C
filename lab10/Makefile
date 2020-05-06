
CXX = g++ -fPIC

all: git IRCServer

IRCServer: IRCServer.cpp
	g++ -g -o IRCServer IRCServer.cpp

git:
	#Do not remove or comment these lines. They are used for monitoring progress.
	git add *.h *.cpp >> local.git.out 2>&1 || echo
	git add total.txt >> local.git.out 2>&1 || echo
	git add local.git.out >> local.git.out 2>&1 || echo
	git commit -a -m "Lab10" >> local.git.out 2>&1 || echo

clean:
	rm -f *.out
	rm -f *.o HashTableVoidTest IRCServer


