//Burak Çakan - 702201003 - 04.02.2020

#include<iostream>
#include<list>
#include<set>
#include<string>
#include<fstream>
#include<map>

using namespace std;

class Matrix_COO{
private:
map<int, map<int, double>> coo_map;


public:

Matrix_COO(string path_file){
		ifstream infile(path_file);

		int n_lines;
		infile>>n_lines;
		int n=n_lines;
		infile>>n_lines;
		int m=n_lines;

		double matrix[(int)n][(int)m];

		int row=0;
		while(!infile.eof()){
		infile>>matrix[row][0]>>matrix[row][1]>>matrix[row][2]>>matrix[row][3]>>matrix[row][4]>>matrix[row][5]>>matrix[row][6];
		row=row+1;
		}

		string line;
		getline(infile, line);

		int index=0;
		for(int i=0;i<n;i++){ 
			for(int j=0;j<m;j++){
				if(matrix[i][j]!=0){
				coo_map[i+1][j+1]=matrix[i][j];
				}
			}
		}

	}
		void show(){
		map<int, map<int, double>>::iterator iter1; 
		map<int, double>::iterator iter2;
		cout<<"Row"<<"\t"<<"Col"<<"\t"<<"Value"<<endl;
		for(iter1=coo_map.begin();iter1!=coo_map.end();iter1++){
			cout<<(*iter1).first<<"\t";
			(*iter1).second; 
			int counter=0;
			for(iter2=(*iter1).second.begin();iter2!=(*iter1).second.end();iter2++){
				if(counter>1){
				cout<<(*iter1).first<<"\t"<<(*iter2).first<<"\t"<<(*iter2).second<<endl;
				}
				else{
				cout<<(*iter2).first<<"\t"<<(*iter2).second<<endl;
				counter +=1;	
				}
				counter +=1;
				
		   }
	    }
	}
};

int main(){
Matrix_COO Data("q3-input.txt");
Data.show();

return 0;
}