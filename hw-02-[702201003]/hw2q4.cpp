/*
$ g++ hw2q4.cpp
Burak Çakan - 702201003 - 11.01.2020
Generally, I am making steps of hw2q3 in class statement here. T
he only difference is using throw statements when it is neccessary.
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Matrix_COO{
public:
double n;
double m;
int counter;
float* row_index;
float* col_index;
float* value;
public:
	Matrix_COO():row_index(NULL),col_index(NULL),value(NULL){double n=0; double m=0; int counter=0;}
	Matrix_COO(string path_file){
		ifstream infile(path_file);
		if(!infile.is_open()){throw "file cannot be opened";}

		//double n,m;
		double n_lines;
		infile>>n_lines;
		n=n_lines;
		infile>>n_lines;
		m=n_lines;
		double diff1,diff2;
		diff1=n-(int)n;
		diff2=m-(int)m;
		
		if(diff1!=0.) {throw n;}
			else if(diff2!=0.) {throw m;}
		

		float matrix[(int)n][(int)m];
		//cout<<n<<" "<<m<<endl;
		int row=0;
		while(!infile.eof()){
		infile>>matrix[row][0]>>matrix[row][1]>>matrix[row][2]>>matrix[row][3]>>matrix[row][4]>>matrix[row][5]>>matrix[row][6];
		row=row+1;
		}
		if(row!=7){throw row;}

		int counter=0;
		for(int i=0;i<n;i++){ 
			for(int j=0;j<m;j++){
				if(matrix[i][j]!=0){
					counter += 1;
				}
			}
		}
		//cout<<counter<<endl;
		this->counter = counter;
		row_index = new float [counter];
		col_index = new float [counter];
		value = new float [counter];

		infile.clear(); // to return to the beginning of the file
		infile.seekg(0);
		string line;
		getline(infile, line);

		for(int row=0;row<m;row++){ 
		infile>>matrix[row][0]>>matrix[row][1]>>matrix[row][2]>>matrix[row][3]>>matrix[row][4]>>matrix[row][5]>>matrix[row][6];
		}

		int index=0;
		for(int i=0;i<n;i++){ 
			for(int j=0;j<m;j++){
				if(matrix[i][j]!=0){
				row_index[index]=i+1;
				col_index[index]=j+1;
				value[index]=matrix[i][j];
				index += 1;
				}
			}
		}
		//cout<<this->n<<" "<<this->m<<endl;
		//for(int i=0;i<counter;i++){ 
		//cout<<row_index[i]<<" "<<col_index[i]<<" "<<value[i]<<endl;
		//}

	}

	~Matrix_COO(){
		if(value!=NULL) {
			delete[] value;}

		if(row_index!=NULL) {
			delete[] row_index;}

		if(col_index!=NULL) {
			delete[] col_index;}
	}

	void show(){
		cout<<this->n<<" "<<this->m<<endl;
		for(int i=0;i<this->counter;i++){ 
		cout<<this->row_index[i]<<" "<<this->col_index[i]<<" "<<this->value[i]<<endl;
		if(counter==6) break;

		}
	}

};



int main()
{
	try{
		Matrix_COO Data("q4-input-exc2.txt");
		cout<<"successfully read"<<endl;
		Data.show();
	}catch(const char* exp){ 
		cout<<exp<<endl; 
	}catch(const double sth){
		cout<<"first two entries are not integers: "<<sth<<endl;
	}catch(const int abc){
		cout<<"couldn't read until eof"<<endl;
	}catch(...){cout<<"an exception i dont know"<<endl;}




	


}


/*

int main()
{
	ifstream infile("q3-input.txt");

	string line;
	getline (infile,line);
	cout<<line<<endl;

}

*/