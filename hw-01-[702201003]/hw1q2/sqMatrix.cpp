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



 
