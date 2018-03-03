output: main.o Menu.o Character.o Barbarian.o Combat.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Queue.o Node.o
	g++ -g -std=c++0x main.o Menu.o Character.o Barbarian.o Vampire.o BlueMen.o Medusa.o HarryPotter.o Combat.o Queue.o Node.o -o main

main.o: main.cpp
	g++ -c -g -std=c++0x main.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c -g -std=c++0x Menu.cpp

Character.o: Character.cpp Character.h
	g++ -c -g -std=c++0x Character.cpp

Barbarian.o: Barbarian.cpp Barbarian.h
	g++ -c -g -std=c++0x Barbarian.cpp

Vampire.o: Vampire.cpp Vampire.h
	g++ -c -g -std=c++0x Vampire.cpp

BlueMen.o: BlueMen.cpp BlueMen.h
	g++ -c -g -std=c++0x BlueMen.cpp

Medusa.o: Medusa.cpp Medusa.h
	g++ -c -g -std=c++0x Medusa.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.h
	g++ -c -g -std=c++0x HarryPotter.cpp

Combat.o: Combat.cpp Combat.h
	g++ -c -g -std=c++0x Combat.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c -g -std=c++0x Queue.cpp

Node.o: Node.cpp Node.h
	g++ -c -g -std=c++0x Node.cpp

val:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes ./main

clean:
	rm *.o main