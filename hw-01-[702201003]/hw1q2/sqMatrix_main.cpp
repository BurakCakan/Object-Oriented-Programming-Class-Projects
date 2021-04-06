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
	cout<<"Default Matrix:"<<endl;
	a.show(n); // to see full zero matrix

	//for(i=0;i<n;i++) cout<<a.array[i]<<"\t"; cout<<endl; //  to check if the memory allocated contigously 

	//delete[] a.array[1];
	// to check the deconstructor and deconstructor delete the array
	// because I take "double free , aborted(core dumped) error"
	// that means I am tyring to free a place in memort that already got free

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
	cout<<"Transposed Matrix:"<<endl;
	a.transpose(n);

}