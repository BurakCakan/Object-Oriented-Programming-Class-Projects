// Burak ÇAKAN - 702201003

#include<iostream>
#include <cstddef>
#include "sqMatrix.h"

using namespace std;

sqMatrix::sqMatrix(int n): size(n){ //parametrized constructor
		int i,j;
		array = new double* [n]; // def of 2d array with allocated memeory
		for(i=0;i<n;i++) array[i]=new double [n]; // for contigous memeory in matrix

		for(i=0;i<n;i++) {	// to built in the nxn matrix
			for(j=0;j<n;j++){
				array[i][j]=0.;}
		}
	}

sqMatrix::sqMatrix(const sqMatrix& other){ //copy constructor
	if(array!=NULL) delete[] array;
		size=other.size;
		array=new double* [size];
		for(int i=0;i<size;i++) {this->array[i] = new double [size];}
		for(int i=0;i<size;i++) {
			for(int j=0;j<size;j++){
				this->array[i][j]=0;
			}
		}
	}

sqMatrix::~sqMatrix(){ // deconstructor 
		if(array!=NULL) {
		for(int i=0;i<size;i++) delete[] array[i];
		delete[] array;}
	}

void sqMatrix::get(int r, int c, double indice){
		array[r][c]= indice;
	}

void sqMatrix::show(int n){

		for(int i=0;i<n;i++){ 
			for(int j=0;j<n;j++) {
			cout<<array[i][j]<<"\t";}
		cout<<endl;}
	}

void sqMatrix::transpose(int n){

		double** transposed_array;
		transposed_array = new double* [n]; 
		for(int i=0;i<n;i++) transposed_array[i]=new double [n];

		for(int i=0;i<n;i++){ 
			for(int j=0;j<n;j++) {
			transposed_array[j][i]=array[i][j];}
		}

		for(int i=0;i<n;i++){ 
			for(int j=0;j<n;j++) {
			cout<<transposed_array[i][j]<<"\t";}
		cout<<endl;}

		for(int i=0;i<n;i++) delete[] transposed_array[i];
		delete[] transposed_array;
	}

sqMatrix sqMatrix::operator + (double h)const{ 
	sqMatrix to_return(this->size);  

	for(int i=0;i<this->size;i++){
		for(int j=0;j<this->size;j++){
		to_return.array[i][j]=this->array[i][j]+h;} 
	}
		
	return to_return;
	}

sqMatrix sqMatrix::operator + (const sqMatrix& m){ 
	if (sqMatrix::size != m.size){
		cout<<"Assignment Error: Matrices must have same dimensions!"<<endl;
		exit(1);}
	sqMatrix to_return(this->size);  
	for(int i=0;i<this->size;i++){
		for(int j=0;j<this->size;j++){
		to_return.array[i][j]=this->array[i][j]+m.array[i][j];} 
	}
		
	return to_return;
	}

sqMatrix sqMatrix::operator - (double g)const{ 
	sqMatrix to_return(this->size);  

	for(int i=0;i<this->size;i++){
		for(int j=0;j<this->size;j++){
		to_return.array[i][j]=this->array[i][j]-g;} 
	}
		
	return to_return;
	}
//Below overloading operator is used to assign all elements of a matrix to another matrix
	
sqMatrix& sqMatrix::operator = (const sqMatrix& rhs){ 
		if (&rhs==this){
			return *this;}
// if rhs matrix is the same as lhs following of this function is ambigous 
		else if (sqMatrix::size != rhs.size){
			cout<<"Assignment Error: Matrices must have same dimensions!"<<endl;
			exit(1);}
// when used inappropriately because of size this error message occurs 

		for(int i=0;i<this->size;i++){
			for(int j=0;j<this->size;j++){
				this->array[i][j]=rhs.array[i][j];} 
		}
		
	return *this;
	}
// Below assignment operator is used to assign a double value to all elements of the matrix
	
sqMatrix sqMatrix::operator == (double addi)const{ 
		for(int i=0;i<this->size;i++){
			for(int j=0;j<this->size;j++){
				this->array[i][j]=addi;} 
		}
		
	return *this;
	}

sqMatrix& sqMatrix::operator +=(const sqMatrix& mat){

		if (sqMatrix::size != mat.size){
			cout<<"Assignment Error: Matrices must have same dimensions!"<<endl;
			exit(1);}

		for(int i=0;i<this->size;i++){
			for(int j=0;j<this->size;j++){
				this->array[i][j]+=mat.array[i][j];} 
		}
	return *this;
	}

sqMatrix& sqMatrix::operator -=(double t){
	sqMatrix to_return(this->size); 
		for(int i=0;i<this->size;i++){
			for(int j=0;j<this->size;j++){
				this->array[i][j]-=t;} 
		}
	return *this;
	}


sqMatrix operator + (double a, const sqMatrix& b){
		// bu fonksiyon b=3.5+a işlemini yapabilmek için kullanılır
	sqMatrix to_return(b.size);						
	for(int i=0;i<to_return.size;i++){
		for(int j=0;j<to_return.size;j++)
			{to_return.array[i][j]=b.array[i][j]+a;}
	}
	return to_return;	
	}   
