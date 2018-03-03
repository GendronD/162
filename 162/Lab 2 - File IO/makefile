output: fileMain.o outputFile.o inputFile.o
	g++ -std=c++0x fileMain.o outputFile.o inputFile.o -o fileMain

fileMain.o: fileMain.cpp
	g++ -c -std=c++0x fileMain.cpp

outputFile.o: outputFile.cpp
	g++ -c -std=c++0x outputFile.cpp

inputFile.o: inputFile.cpp
	g++ -c -std=c++0x inputFile.cpp

clean:
	rm *.o fileMain