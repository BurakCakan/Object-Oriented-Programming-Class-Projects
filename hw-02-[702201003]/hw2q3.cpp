/*
$ g++ hw2q3.cpp
Burak Çakan - 702201003 - 11.01.2020
In this script, I am reading a common matrix and counting nnz values of it. Then, I am converting it to COO Matrix.
And I will write this coo matrix on both on the terminal and the file named data.txt.
*/

#include<iostream>
#include <fstream>

using namespace std;

int main()
{

	ifstream infile("q3-input.txt");
	int row,col;
	int n_lines;
	infile>>n_lines;
	row=n_lines;
	infile>>n_lines;
	col=n_lines;

	float matrix[row][col]; // tüm satırları atmak için matrix kuruyor
	
	for(int i=0;i<row;i++){ 
		for(int j=0;j<col;j++){
		infile>>matrix[i][j];
		}
	}
	
	int counter=0;

	for(int i=0;i<row;i++){ 
		for(int j=0;j<col;j++){
			if(matrix[i][j]!=0){
				counter += 1;
			}
		}
	}

	float* row_index = new float [counter];
	float* col_index = new float [counter];
	float* value = new float [counter];
	int index=0;

	for(int i=0;i<row;i++){ 
		for(int j=0;j<col;j++){
			if(matrix[i][j]!=0){

				row_index[index]=i+1;
				col_index[index]=j+1;
				value[index]=matrix[i][j];
				index += 1;
			}
		}
	}

	cout<<counter<<" "<<"3"<<endl;
	for(int i=0;i<counter;i++){ 
		cout<<row_index[i]<<" "<<col_index[i]<<" "<<value[i]<<endl;
	}

	ofstream mydata("data.txt");
	mydata<<counter<<" "<<"3"<<endl; // there must be 3 files so number of columns must be 3 in each case, so I used 3 directly
	for(int i=0;i<counter;i++){ 
		mydata<<row_index[i]<<" "<<col_index[i]<<" "<<value[i]<<endl;
	}

	delete[] row_index;
	delete[] col_index;
	delete[] value;

}