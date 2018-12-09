all : change

change : change.o
	g++ -g -std=c++0x change.o -o change

change.o: change.cpp
	g++ -c -g -std=c++0x change.cpp

.PHONY : clean memCheckChange

memCheckChange:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes change



clean:
	-rm *.o
	-rm change