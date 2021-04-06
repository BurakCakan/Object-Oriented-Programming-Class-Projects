//Burak Çakan - 702201003 - 04.02.2020

#include<iostream>
#include<list>
//#include<algorithm>

using namespace std;

int main(){

 	list<int> list1,list2;
 	list<int>::iterator it=list1.end();
 	list<int>::iterator iter=list1.begin(); 

 	for(int i=0;i<5;i++) list1.push_back(i);

 //	for(iter= list1.begin();iter!=list1.end();iter++){cout<<*iter<<endl;}
/*
 	while(iter!=list1.end()){
 		cout<<*iter<<endl;
 		++iter;
 	}
*/
 	while(it!=list1.begin()){
 		--it;
 		list2.push_back(*it);
 	}

 	swap(list1,list2);

 	cout<<"bb"<<endl;
 	while(iter!=list1.end()){
 		cout<<"aaa"<<endl;
 		cout<<*iter<<endl;
 		iter++;
 	}


 	cout<<"-------------------------------------------"<<endl;
 
 for(iter= list1.begin();iter!=list1.end();iter++){cout<<*iter<<endl;}

 	
// return 0;
};