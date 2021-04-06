// Burak ÇAKAN - 702201003
#include<iostream>
#include "sqMatrix.h"

using namespace std;

int main(){

	int i,j,n;

	n=5;

	sqMatrix a(n);

	for(i=0;i<n;i++){ // to print matrix in class
		for(j=0;j<n;j++) {
			cout<<a.array[i][j]<<"\t";
		}
		cout<<endl;
	}

	for(i=0;i<n;i++) cout<<a.array[i]<<"\t"; cout<<endl; 
	//  to check if the memory allocated contigously 

}