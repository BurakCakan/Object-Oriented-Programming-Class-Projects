// Burak Çakan - Script to take argument from terminal and to form arrays with pointers
#include<iostream>
#include<stdlib.h>
using namespace std;

void bubbleSort(int *a,int n){  //I have used bubble sorting
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){ 
			if (a[j]>a[j+1]){
			int temp = a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
			}
		}
	}
}

void printArray(int *a, int n){   // I defined function to print array
	for(int i=0; i<n;i++){
		cout<<" "<<a[i];
		}
	cout<<endl;
	}
	
int main(int argc, char * argv[]){
	int m,k;

	if(argc<2) {cout<<"Error"<<endl;return 1;} 
	int n = atoi(argv[1]); //gives array size
	int* a = new int[n];

	for(m=0;m<n;m++){
		cout<<"Enter number:"<<endl;
		cin>>a[m];
		}
	cout<<"Array before sorting is: "<<endl;
	printArray(a,n);
	cout<<"Array after bubble sorting is: "<<endl;
	bubbleSort(a,n);
	printArray(a,n);
	delete a;

}


