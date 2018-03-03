output: main.o InputValidation.o Menu.o Recursive.o
	g++ -g -std=c++0x main.o InputValidation.o Menu.o Recursive.o -o main

main.o: main.cpp
	g++ -g -c -std=c++0x main.cpp

InputValidation.o: InputValidation.cpp
	g++ -g -c -std=c++0x InputValidation.cpp

Menu.o: Menu.cpp
	g++ -g -c -std=c++0x Menu.cpp

Recursive.o: Recursive.cpp
	g++ -g -c -std=c++0x Recursive.cpp

clean:
	rm *.o main