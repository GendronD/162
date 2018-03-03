output: antMain.o startMenu.o endMenu.o promptUserMenu.o inputValidation.o antClass.o
	g++ -std=c++0x antMain.o startMenu.o endMenu.o promptUserMenu.o inputValidation.o antClass.o -o antMain

antMain.o: antMain.cpp
	g++ -c -std=c++0x antMain.cpp

startMenu.o: startMenu.cpp
	g++ -c -std=c++0x startMenu.cpp

endMenu.o: endMenu.cpp
	g++ -c -std=c++0x endMenu.cpp

promptUserMenu.o: promptUserMenu.cpp
	g++ -c -std=c++0x promptUserMenu.cpp

inputValidation.o: inputValidation.cpp
	g++ -c -std=c++0x inputValidation.cpp

antClass.o: antClass.cpp
	g++ -c -std=c++0x antClass.cpp


clean:
	rm *.o antMain