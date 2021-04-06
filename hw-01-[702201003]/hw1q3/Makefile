
output: sqMatrix_main.o sqMatrix.o
	g++ sqMatrix_main.o sqMatrix.o -o output

sqMatrix_main.o: sqMatrix_main.cpp
	g++ -c sqMatrix_main.cpp

sqMatrix.o: sqMatrix.cpp sqMatrix.h
	g++ -c sqMatrix.cpp 

clean: 
	rm *.o output 