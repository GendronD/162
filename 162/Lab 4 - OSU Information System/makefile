output: main.o University.o inputValidation.o Menu.o Person.o Student.o Instructor.o Building.o
	g++ -g -std=c++0x main.o University.o inputValidation.o Menu.o Person.o Student.o Instructor.o Building.o -o main

main.o: main.cpp
	g++ -g -c -std=c++0x main.cpp

University.o: University.cpp
	g++ -g -c -std=c++0x University.cpp

inputValidation.o: inputValidation.cpp
	g++ -g -c -std=c++0x inputValidation.cpp

Menu.o: Menu.cpp
	g++ -g -c -std=c++0x Menu.cpp

Person.o: Person.cpp
	g++ -g -c -std=c++0x Person.cpp

Student.o: Student.cpp
	g++ -g -c -std=c++0x Student.cpp

Instructor.o: Instructor.cpp
	g++ -g -c -std=c++0x Instructor.cpp

Building.o: Building.cpp
	g++ -g -c -std=c++0x Building.cpp


clean:
	rm *.o main