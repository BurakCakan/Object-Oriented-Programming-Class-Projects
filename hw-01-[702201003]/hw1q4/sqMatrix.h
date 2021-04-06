// Burak ÇAKAN - 702201003

#include <cstddef>
// only include class definiitons 
#ifndef sqMatrix_H
// Burak ÇAKAN - 702201003
#define sqMatrix_H

class sqMatrix{
public:
	int size; // size of square matrix
	double** array=NULL;

sqMatrix(): size(0),array(NULL) {}
sqMatrix(int n);
sqMatrix(const sqMatrix& other);
~sqMatrix();

void get(int r, int c, double indice);
void show(int n);
void transpose(int n);

sqMatrix operator + (double h)const;
sqMatrix operator + (const sqMatrix& m);
sqMatrix operator - (double g)const;
sqMatrix& operator = (const sqMatrix& rhs);
sqMatrix operator == (double addi)const;
sqMatrix& operator +=(const sqMatrix& mat);
sqMatrix& operator -=(double t);
friend sqMatrix operator +(double a, const sqMatrix& b);
double* GaussE(double* v);

};

sqMatrix operator + (double a, const sqMatrix& b);

#endif
//  g++ class_cyclic_main.cpp class_cyclic.h class_cyclic.cpp -I.