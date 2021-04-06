// Burak ÇAKAN - Script for finding median of the array
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int a,b;
int *p;
int *k;
cout<<"Enter the Size of the Array:";
cin>>a;
if (a<1){cout<<"You should enter a valid size for array.";
}
else {
	p= new int[a]; // to allocate memory dynamically
	for(b=0;b<a;b++){ 
		cout<<"Enter the number: ";
		cin>>p[b];
		}
	cout<<"Your array is: ";
	for(b=0;b<a;b++){ 
		cout<<p[b]<<",";
		}
	cout<<endl;
	k=new int[a]; //to store the original form of array before sorting

	for(b=0;b<a;b++){ 
		k[b]=p[b];
		}
	sort(p,p+a); // a built-i funcion to be used to sort the array to find median

	cout<<endl;
	if (a%2==1){
	cout<<"Median value is: ";
	cout<<p[a/2]<<endl;	
	cout<<"Adress of the Median is: ";
	cout<<&p[a/2]<<endl;
	int m=p[a/2];
	int i=0;
		while(i<a){
			if(k[i]==m){break;} // used to find the index number of median
		i++;
		}
		if(i<a){
		cout<<"Index number is: "<< i<<endl; 
		} 
		}
	else {
	cout<<"Median value is: ";
	cout<<double(p[a/2]+p[(a/2)-1])/2<<endl;
	cout<<"Adress and index cannot be given for even-sized arrays";	
	}
	}	
	delete[] p;

return 0;
}
