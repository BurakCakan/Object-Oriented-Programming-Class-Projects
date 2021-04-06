//Burak Çakan - 702201003 - 04.02.2020
#include<iostream>
#include<list>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

int array[]={2,4,6,8};
int array2[]={1,3,5,7};
set<int> s(array2,array2+4);
vector<int> vect(8);
merge(array,array+4,s.begin(),s.end(),vect.begin());

cout<<"merged vector is:"<<endl;
for(int i=0;i<8;i++){
	cout<<vect[i]<<"  ";
}


return 0;
}