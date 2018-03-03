
output: main.o InputValidation.o MenuPrompts.o Queue.o 
	g++ -std=c++0x main.o InputValidation.o MenuPrompts.o Queue.o -o main

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

InputValidation.o: InputValidation.cpp InputValidation.h
	g++ -std=c++0x -c InputValidation.cpp

MenuPrompts.o: MenuPrompts.cpp MenuPrompts.h
	g++ -std=c++0x -c MenuPrompts.cpp

Queue.o: Queue.cpp Queue.h
	g++ -std=c++0x -c Queue.cpp

clean:
	rm *.o main
