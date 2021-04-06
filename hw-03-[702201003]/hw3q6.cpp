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
public:
vector<int> vect1;
vector<int> vect2;
vector<double> vect3;
string path;
int n;
int m;
public:
	Matrix_COO(){}
	Matrix_COO(string path_file){
		path=path_file;
		ifstream infile(path_file);

		int n_lines;
		infile>>n_lines;
		n=n_lines;
		infile>>n_lines;
		m=n_lines;

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

	Matrix_COO(Matrix_COO &other){   //copy constructor
	vector<int> vect1(other.vect1);
	vector<int> vect2(other.vect2);
	vector<double> vect3(other.vect3);
	n = other.n;
	m = other.m;
	path=other.path;
		ifstream infile(path);

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

		void dot(Matrix_COO& obj2) {

			if (this->m != obj2.n){
				cout<<"Invalid size";}

			int a = obj2.m;

			double result[this->n][a];
			double sum;

			for(int i=0; i<this->n;i++) {


				for(int j=0; j<obj2.m;j++) {

					sum = 0;

					for(int k=0; k<this->vect1.size();k++) {

						if (this->vect1[k] == i+1) {

							for(int c=0; c<obj2.vect2.size();c++) {

								if ( obj2.vect2[c] == j+1 && obj2.vect1[c] == this->vect2[k] ) {

									sum += this->vect3[k]*obj2.vect3[c];
								

								}

							}

						}
					}

					result[i][j] = sum;

				}

			}

			for(int i=0; i<this->n;i++) {
				for(int j=0; j<obj2.m;j++) {
					cout<<result[i][j]<<" ";
				}
				cout<<endl;
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

const Matrix_COO operator + (const Matrix_COO& obj1, const Matrix_COO& obj2){
// tamamen ayni matrixler yerine farklı matrixler verilmesi durumları da oldugu icin cok fazla condition kullandim
	Matrix_COO result;

	int checked[obj2.vect1.size()]={};

	for (int i=0;i<obj1.vect1.size();i++){
		if(obj1.vect1[i]==obj2.vect1[i] && obj2.vect2[i]==obj1.vect2[i]){ // tamamen aynı matrixler icin
			result.vect1.push_back(obj1.vect1[i]);
			result.vect2.push_back(obj1.vect2[i]);
			result.vect3.push_back(obj1.vect3[i]+obj2.vect3[i]);
			checked[i] = 1;
		}else{
			int r=obj1.vect1[i];
			int c=obj1.vect2[i];
			double v=obj1.vect3[i];
			int is_chechked=0; //1. matrixdeki degerin eslesip eslesmedigini bulur
			int check=0;
			for(int k=0;k<obj2.vect1.size();k++){
				if(r==obj2.vect1[k] && c==obj2.vect2[k]){
					result.vect1.push_back(r);
					result.vect2.push_back(c);
					result.vect3.push_back(v+obj2.vect3[k]);
					is_chechked=1;
					//check=k;
					checked[k] = 1;
					break;
				}
			}
			if(is_chechked==0){
					result.vect1.push_back(r);
					result.vect2.push_back(c);
					result.vect3.push_back(v);
			}

		//	if(i!=check){
		//			result.vect1.push_back(obj2.vect1[i]);
		//			result.vect2.push_back(obj2.vect2[i]);
		//			result.vect3.push_back(obj2.vect3[i]);
		//	}


		}
	}

	for (int i=0;i<obj2.vect1.size();i++){
		if (checked[i] == 0) {
			result.vect1.push_back(obj2.vect1[i]);
			result.vect2.push_back(obj2.vect2[i]);
			result.vect3.push_back(obj2.vect3[i]);		
		}
	}



		cout<<"row indexes: "<<endl;
		for(int i=0;i<result.vect1.size();i++){ 
		cout<<result.vect1[i]<<" ";
		}
		cout<<endl;
		cout<<"column indexes: "<<endl;
		for(int i=0;i<result.vect2.size();i++){ 
		cout<<result.vect2[i]<<" ";
		}
		cout<<endl;
		cout<<"nnz values: "<<endl;
		for(int i=0;i<result.vect3.size();i++){ 
		cout<<result.vect3[i]<<" ";
		}
		cout<<endl;

		return result;

}

//const Matrix_COO operator * (const Matrix_COO& obj1, const Matrix_COO& obj2){
//Matrix_COO result;


//	}

int main(){
Matrix_COO Data("deneme.txt");
Matrix_COO Datax("deneme.txt");
Data.dot(Datax); // bu member functionda bazi hatalar yaptıgım icin bu sorudaki diger * operator overloadingleri yapamadim 
//Matrix_COO Datax("q4-input-exc2.txt");
//Data+Datax; // + overeloading of two sparse matrix 
//Data.show();
//Datax.show();

return 0;
}