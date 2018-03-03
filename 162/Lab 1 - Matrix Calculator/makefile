output: matrixCalcMain.o readMatrix.o determinant.o printMatrix.o
	g++ matrixCalcMain.o readMatrix.o determinant.o printMatrix.o -o Matrix

matrixCalcMain.o: matrixCalcMain.cpp
	g++ -c matrixCalcMain.cpp

readMatrix.o: readMatrix.cpp
	g++ -c readMatrix.cpp

determinant.o: determinant.cpp
	g++ -c determinant.cpp

printMatrix.o: printMatrix.cpp
	g++ -c printMatrix.cpp

clean:
	rm *.o Matrix