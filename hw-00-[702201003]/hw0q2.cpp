// Burak Çakan - This script is a multiplication table of the input value.
#include <iostream>
using namespace std;
int main(){
int a,c,n;
cout<<"Please enter an integer value:";
cin>>n;
a=n;
for(c=1;c<=10;c++){
cout<<a<<"*"<<c<<"="<<a*c<<endl;
}
}
