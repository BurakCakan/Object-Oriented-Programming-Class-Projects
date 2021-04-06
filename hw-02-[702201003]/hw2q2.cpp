/*
$ g++ hw2q2.cpp
Burak Çakan - 702201003 - 11.01.2020
In this script, I am making conversiions with using template
*/
#include<iostream>

using namespace std;

template <class T2,class T3,class T4>
void swap_arr (T2 &x, T3 &y, T4 N){
	T2 x_temp;
	T3 y_temp;

	for(int i=0;i<N;i++){
		x_temp[i]=x[i];
		y_temp[i]=y[i];
	}

		for(int i=0;i<N;i++){
		x[i]=y_temp[i];
		y[i]=x_temp[i];
	}
}

int main()
{
	// int arr1[4]={1,2,3,4};
	// double arr1[4]={1.1,2.1,3.1,4.1};
	char arr1[4]={'A','b','c','d'};
	//int arr2[4]={4,3,2,1};
	double arr2[4]={70.2,71.2,73.2,74.2};

	swap_arr(arr1,arr2,4);

// I have used these two cout statements to test my script
	cout<<arr1[1]<<endl;
	cout<<arr2[0]<<endl;

}
