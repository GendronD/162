output: main.o Menu.o Character.o Cottage.o Dirt_Path.o Event.o Field.o Forest.o Game_Simulation.o Glade.o Lair.o Mountain_Pass.o Ridge.o Rift_Gate.o Space.o
	g++ -g -std=c++0x main.o Menu.o Character.o Cottage.o Dirt_Path.o Event.o Field.o Forest.o Game_Simulation.o Glade.o Lair.o Mountain_Pass.o Ridge.o Rift_Gate.o Space.o -o main

main.o: main.cpp
	g++ -c -g -std=c++0x main.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c -g -std=c++0x Menu.cpp

Character.o: Character.cpp Character.h
	g++ -c -g -std=c++0x Character.cpp

Cottage.o: Cottage.cpp Cottage.h
	g++ -c -g -std=c++0x Cottage.cpp

Dirt_Path.o: Dirt_Path.cpp Dirt_Path.h
	g++ -c -g -std=c++0x Dirt_Path.cpp

Event.o: Event.cpp Event.h
	g++ -c -g -std=c++0x Event.cpp

Field.o: Field.cpp Field.h
	g++ -c -g -std=c++0x Field.cpp

Forest.o: Forest.cpp Forest.h
	g++ -c -g -std=c++0x Forest.cpp

Game_Simulation.o: Game_Simulation.cpp Game_Simulation.h
	g++ -c -g -std=c++0x Game_Simulation.cpp

Glade.o: Glade.cpp Glade.h
	g++ -c -g -std=c++0x Glade.cpp

Lair.o: Lair.cpp Lair.h
	g++ -c -g -std=c++0x Lair.cpp

Mountain_Pass.o: Mountain_Pass.cpp Mountain_Pass.h
	g++ -c -g -std=c++0x Mountain_Pass.cpp

Ridge.o: Ridge.cpp Ridge.h
	g++ -c -g -std=c++0x Ridge.cpp

Rift_Gate.o: Rift_Gate.cpp Rift_Gate.h
	g++ -c -g -std=c++0x Rift_Gate.cpp

Space.o: Space.cpp Space.h
	g++ -c -g -std=c++0x Space.cpp

val:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes ./main

clean:
	rm *.o main