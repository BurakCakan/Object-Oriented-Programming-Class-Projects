// Burak Çakan - To practice oop structure and contigous memory 
#include<iostream>
using namespace std;

class mtx{
public:
	int N;
	double * array1d;
	double ** array2d;
	
	mtx(int n){    // parametrized constructer
		N = n;
		array1d = new double [n*(n+1)/2];
		array2d = new double * [n];
		for(int i=0;i<n;i++) array2d[i] = &array1d[i*n-((i-1)*i/2)];}
// used for contigous memory for storing the upper triangle part only like: {[x,x,x,x],[x,x,x],[x,x],[x]}
	
	mtx(){} // default constructor

	mtx(mtx &other){   //copy constructor
	N = other.N;
	array1d = new double [N*(N+1)/2];
	array2d = new double * [N];
	for(int i=0;i<N;i++) array2d[i] = &array1d[i*N-((i-1)*i/2)];
	for(int i=0;i<N*(N+1)/2;i++) { array1d[i] = other.array1d[i]; }
	for(int i=0;i<N;i++) { array2d[i] = other.array2d[i]; }
	}

	~mtx(){   //deconstructor 
		delete[] array1d;
		delete[] array2d;
	}
	
	double * dot(double * v) {   // dot method
		double * vec;
		vec = new double [N];
		for (int i=0;i<N;i++) {vec[i] = *v; v++; } 
// takes the adress of the first value in array and calculates other elements in array contigously
		double * result;
		result = new double [N];
		for(int i=0;i<N;i++) {
			result[i] = 0;
			for(int j=0;j<N;j++) { 
//this part makes dot product calculation
				if (j>=i) { 
// this condition is for the upper triangle part including diagonal
					result[i] += array2d[i][j-i]*vec[j];
				}
				else { 
// this condition is the lower triangle part (that I am not storing in memory)
					result[i] += array2d[j][i-j]*vec[j];
				}
			}
		}
		double *r = &result[0]; //result of the calculation is here
		delete[] vec;
		return r;
	}
	};
	
	int main() {
		int n = 3;
		mtx a(n);    
// I am giving only the upper triangle part and only store this part. But I will use the full symmetric matrix for dot product in dot method
		a.array2d[0][0] = 1.0;
		a.array2d[0][1] = 2.0;
		a.array2d[0][2] = 3.0;
		a.array2d[1][0] = 4.0;
		a.array2d[1][1] = 5.0;
		a.array2d[2][0] = 6.0;
		
		double vect[n] = {1.0,3.0,2.0}; //The array for dot product
		double * v = &vect[0];  
		double * r = a.dot(v); 
// I'm only sending the adress of the first element of the array for the dot product
		double * vec;
		vec = new double [n];
		for (int i=0;i<n;i++) {vec[i] = *r; r++; }
// address of the first element of the result matrix is stored in r. Since other elements contigously stored in memory, I can print other elements of result matrix
		for(int i=0;i<n;i++) {cout<<vec[i]<<endl;}

		delete[] vec;
	}
	
	
	
