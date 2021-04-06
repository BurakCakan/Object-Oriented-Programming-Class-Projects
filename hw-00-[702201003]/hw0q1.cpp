// Burak Çakan - To crete patterns with '*' .
#include <iostream>
using namespace std;
//a şıkkı
int main(){  
int i,j,n;
cout<<"Please enter an integer value for (a):";
cin>>n;
for(i=1;i<=n;i++){
	for(j=1;j<=i;j++){
	cout<<"*";
}
cout<<endl;
}
//b şıkkı
int d;
cout<<"Please enter an integer value for (b):";
cin>>n; 
for(i=1;i<=n;i++){
	for(j=1;j<=n-i;j++){cout<<"-";}
	for(d=1;d<=i;d++){cout<<"*";}
cout<<endl;
}
//c şıkkı
cout<<"Please enter an integer value for (c):";
cin>>n; 
for(i=1;i<=n;i++){
	for(j=1;j<=n-i;j++){ cout<<"-"; }
	for(d=1;d<=(i*2-1);d++){cout<<"*";}
cout<<endl;
}
//d şıkkı
int p;   
cout<<"Please enter an integer value for (d):";
cin>>n;
p = (n+1)/2;
for(i=1;i<=p;i++){
	for(j=1;j<=p-i;j++){ cout<<"-"; }
	for(d=1;d<=(i*2-1);d++){cout<<"*";}
cout<<endl;
}
for(i=p;i>=1;i--){
if (n%2 == 1){
	n = n+1;
	continue;
	}
	for(j=1;j<=p-i;j++){ cout<<"-"; }
	for(d=1;d<=(i*2-1);d++){cout<<"*";}
cout<<endl;
}
// e şıkkı
cout<<"Please enter an integer value for (e):";
cin>>n;
p = (n+1)/2;
for(i=1;i<=p;i++){
	for(j=1;j<=p+i-1;j++){ 
		if(j == p-i+1 or j == p+i-1) {cout<<"*"; }
		else { cout<<"-"; }
}
cout<<endl;
}
for(i=p;i>=1;i--){
	if (n%2 == 1){
		n = n+1;
		continue;}
	for(j=1;j<=p+i-1;j++){ 
		if(j == p-i+1 or j == p+i-1) {cout<<"*"; }
		else { cout<<"-"; }
}
cout<<endl;
}

return 0;
}

