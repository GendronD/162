all : stoogesort

stoogesort : stoogesort.o
	g++ -g -std=c++0x stoogesort.o -o stoogesort

stoogesort.o: stoogesort.cpp
	g++ -c -g -std=c++0x stoogesort.cpp

.PHONY : clean memCheckStoogeSort

memCheckStoogeSort:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes stoogesort



clean:
	-rm *.o
	-rm stoogesort