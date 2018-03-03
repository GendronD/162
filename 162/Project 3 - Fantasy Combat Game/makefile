output: main.o Menu.o Character.o Barbarian.o Combat.o Vampire.o BlueMen.o Medusa.o HarryPotter.o
	g++ -g -std=c++0x main.o Menu.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Combat.o -o main

main.o: main.cpp
	g++ -c -g -std=c++0x main.cpp

Menu.o: Menu.cpp
	g++ -c -g -std=c++0x Menu.cpp

Character.o: Character.cpp
	g++ -c -g -std=c++0x Character.cpp

Barbarian.o: Barbarian.cpp
	g++ -c -g -std=c++0x Barbarian.cpp

Vampire.o: Vampire.cpp
	g++ -c -g -std=c++0x Vampire.cpp

BlueMen.o: BlueMen.cpp
	g++ -c -g -std=c++0x BlueMen.cpp

Medusa.o: Medusa.cpp
	g++ -c -g -std=c++0x Medusa.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -c -g -std=c++0x HarryPotter.cpp

Combat.o: Combat.cpp
	g++ -c -g -std=c++0x Combat.cpp

clean:
	rm *.o main