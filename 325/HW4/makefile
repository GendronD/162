all : act

act : act.o
	g++ -g -std=c++0x act.o -o act

act.o: act.cpp
	g++ -c -g -std=c++0x act.cpp

.PHONY : clean memCheckAct

memCheckAct:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes act



clean:
	-rm *.o
	-rm act