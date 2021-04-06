// Burak ÇAKAN - 702201003

#include <cstddef>
// only include class definiitons 
#ifndef sqMatrix_H
#define sqMatrix_H

class sqMatrix{
public:
	int size; // size of square matrix
	double** array=NULL;

sqMatrix(): size(0),array(NULL) {}
sqMatrix(int n);
sqMatrix(const sqMatrix& other);
~sqMatrix();

};

#endif
//  g++ class_cyclic_main.cpp class_cyclic.h class_cyclic.cpp -I.