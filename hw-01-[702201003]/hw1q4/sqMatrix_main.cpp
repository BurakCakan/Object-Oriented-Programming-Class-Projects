// Burak ÇAKAN - 702201003
#include<iostream>
#include "sqMatrix.h"

using namespace std;

int main(){

	int i,j,n;
	double ind;

	n=3;

	sqMatrix a(n);


	cout<<endl;
	for(i=0;i<n;i++){      // this is used to get elements of the matrix with get method in main 
		for(j=0;j<n;j++){
			cout<<"Enter the value of "<<i+1<<"th row and "<<j+1<<"th column:"<<endl;
			cin>>ind;
			a.get(i,j,ind);
		}
	}

	cout<<endl;
	cout<<"Filled Matrix:"<<endl;
	a.show(n); // to see filled  matrix
	cout<<endl;

	double* y;
	y = new double [n];
	cout<<"Enter the elements of array"<<endl;
	for (int i=0;i<n;i++){cin>>y[i];}

	a.GaussE(y);
	cout<<endl;
	cout<<"Original Matrix"<<endl; // to show that given matrix is not changed
	a.show(n);
	cout<<"Original Array"<<endl; // to see that our given array is not changed 
	for(int i=0; i<n;i++){cout<<y[i]<<endl;}
}