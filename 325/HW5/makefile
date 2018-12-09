all : wrestler

wrestler : wrestler.o
	g++ -g -std=c++0x wrestler.o -o wrestler

wrestler.o: wrestler.cpp
	g++ -c -g -std=c++0x wrestler.cpp

.PHONY : clean memCheckWrestler

memCheckWrestler:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes wrestler



clean:
	-rm *.o
	-rm wrestler