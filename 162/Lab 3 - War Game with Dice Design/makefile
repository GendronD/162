output: gameMain.o gameMenu.o promptPlayer.o inputValidation.o dieClass.o loadedDieClass.o gameClass.o
	g++ -g -std=c++0x gameMain.o gameMenu.o promptPlayer.o inputValidation.o dieClass.o loadedDieClass.o gameClass.o -o gameMain

gameMain.o: gameMain.cpp
	g++ -c -g -std=c++0x gameMain.cpp

gameMenu.o: gameMenu.cpp
	g++ -c -g -std=c++0x gameMenu.cpp

promptPlayer.o: promptPlayer.cpp
	g++ -c -g -std=c++0x promptPlayer.cpp

inputValidation.o: inputValidation.cpp
	g++ -c -g -std=c++0x inputValidation.cpp

dieClass.o: dieClass.cpp
	g++ -c -g -std=c++0x dieClass.cpp

loadedDieClass.o: loadedDieClass.cpp
	g++ -c -g -std=c++0x loadedDieClass.cpp

gameClass.o: gameClass.cpp
	g++ -c -g -std=c++0x gameClass.cpp


clean:
	rm *.o gameMain