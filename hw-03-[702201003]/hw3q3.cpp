//Burak Çakan - 702201003 - 04.02.2020

#include<iostream>
#include<list>
#include<set>
#include<algorithm>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class Matrix_COO{
private:
vector<int> vect1;
vector<int> vect2;
vector<double> vect3;

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
				vect1.push_back(i+1);
				vect2.push_back(j+1);
				vect3.push_back(matrix[i][j]);
				}
			}
		}

	}
		void show(){
		cout<<"row indexes: "<<endl;
		for(int i=0;i<vect1.size();i++){ 
		cout<<vect1[i]<<" ";
		}
		cout<<endl;
		cout<<"column indexes: "<<endl;
		for(int i=0;i<vect2.size();i++){ 
		cout<<vect2[i]<<" ";
		}
		cout<<endl;
		cout<<"nnz values: "<<endl;
		for(int i=0;i<vect2.size();i++){ 
		cout<<vect3[i]<<" ";
		}
		cout<<endl;
	}
};

int main(){
Matrix_COO Data("q3-input.txt");
Data.show();

return 0;
}