
output: main.o InputValidation.o MenuPrompts.o Node.o 
	g++ -std=c++0x main.o InputValidation.o MenuPrompts.o Node.o -o main

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

InputValidation.o: InputValidation.cpp InputValidation.h
	g++ -std=c++0x -c InputValidation.cpp

MenuPrompts.o: MenuPrompts.cpp MenuPrompts.h
	g++ -std=c++0x -c MenuPrompts.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++0x -c Node.cpp

clean:
	rm *.o main
