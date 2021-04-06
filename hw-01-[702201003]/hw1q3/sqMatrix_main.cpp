// Burak ÇAKAN - 702201003

#include<iostream>
#include "sqMatrix.h"

using namespace std;

int main(){

	int i,j,n;
	double ind;

	n=3;

	sqMatrix a(n);
//	cout<<endl;
//	cout<<"Default Matrix:"<<endl;
//	a.show(n); // to see full zero matrix

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


//	sqMatrix c=a+3.4;
//	cout<<endl;
//	cout<<"Addition operator (matrix+double):"<<endl;

//	for(int i=0;i<c.size;i++){ 
//		for(int j=0;j<c.size;j++) {
//		cout<<c.array[i][j]<<"\t";}
//	cout<<endl;}


	sqMatrix d=a-1.1;
	cout<<endl;
	cout<<"Subtracting operator (matrix-double):"<<endl;

	for(int i=0;i<d.size;i++){ 
		for(int j=0;j<d.size;j++) {
		cout<<d.array[i][j]<<"\t";}
	cout<<endl;}

	int p=3;
	sqMatrix e(p); // I defined to try assignment (=) operator 
	cout<<endl;
	for(i=0;i<p;i++){      // this is used to get elements of the matrix with get method in main 
		for(j=0;j<p;j++){
			cout<<"Enter the value of "<<i+1<<"th row and "<<j+1<<"th column:"<<endl;
			cin>>ind;
			e.get(i,j,ind);
		}
	}

	cout<<endl;
	cout<<"Other defined matrix:"<<endl;
	e.show(p);

	a=e; // calls assignment operator to assign rhs matrix to lhs matrix 
	cout<<endl;
	cout<<"Assigned matrix (Matrix=Other Matrix):"<<endl;
	a.show(3);

	cout<<endl;
	cout<<"Assigned matrix (Matrix=double):"<<endl;
	a==3.3; 
	// Iam calling == operator to assign the double value to all elements of the matrix
	a.show(3);

	a+=e;
	cout<<endl;
	cout<<"Assigned matrix (Matrix+=matrix):"<<endl;
	a.show(3);

	a-=1.1;
	cout<<endl;
	cout<<"Assigned matrix (Matrix-=double):"<<endl;
	a.show(3);

	sqMatrix c(3);
	c=a+e;
	cout<<endl;
	cout<<"Assigned matrix w/o changing a (c=matrix+matrix)"<<endl;
	c.show(3);
	cout<<endl;
	cout<<"Matrix of a:"<<endl;
	a.show(3);
	// in the example above, I make an addition without changing a.

	sqMatrix g=5.1+a;
	cout<<endl;
	cout<<"Assigned matrix w/o changing a (c=double+matrix)"<<endl;
	g.show(3);
	// example above, I make addition of double and matrix with friend operator
}