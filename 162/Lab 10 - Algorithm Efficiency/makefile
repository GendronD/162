output: main.o InputValidation.o Recursive.o Iterative.o
	g++ -g -std=c++0x main.o InputValidation.o Recursive.o Iterative.o -o main

main.o: main.cpp
	g++ -c -g -std=c++0x main.cpp

InputValidation.o: InputValidation.cpp InputValidation.h
	g++ -c -g -std=c++0x InputValidation.cpp

Iterative.o: Iterative.cpp Iterative.h
	g++ -c -g -std=c++0x Iterative.cpp

Recursive.o: Recursive.cpp Recursive.h
	g++ -c -g -std=c++0x Recursive.cpp

val:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes ./main

clean:
	rm *.o main