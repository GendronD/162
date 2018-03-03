output: main.o Menus.o InputValidation.o 
	g++ -g -std=c++0x main.o Menus.o InputValidation.o -o main

main.o: main.cpp
	g++ -c -g -std=c++0x main.cpp

Menus.o: Menus.cpp Menus.h
	g++ -c -g -std=c++0x Menus.cpp

InputValidation.o: InputValidation.cpp InputValidation.h
	g++ -c -g -std=c++0x InputValidation.cpp

val:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes ./main

clean:
	rm *.o main