#include<iostream>

using namespace std;

class N_Quenn{
private:
	int N;
	int sol_counter;
	int* sol;
	int** solutions;
public:

	N_Quenn(int n): N(n), sol_counter(0), solutions(NULL) {
		sol = new int [N];
		for(int i=0;i<N;i++) sol[i]=-1;
	}

	~N_Quenn(){  
		if(sol!=NULL) delete[] sol; 
		if(solutions!=NULL) {
			for(int i=0;i<N;i++) delete[] solutions[i];
			delete[] solutions;}
		}
	

	bool is_feasible(int col){
		if (col==0){return true;}
		else {
		for(int i=0;i<col;i++) {
			if ((sol[i]==sol[col]) or (col+sol[col]==i+sol[i]) or (col-sol[col]==i-sol[i])) {return false;}
			}
			return true;
		}
	}

	void allocate_solution(){
		solutions = new int* [10000]; 
		for(int i=0;i<10000;i++) solutions[i]=new int [N];
		// number of rows should be the number of feasible solutions but we dont know the exact number beforehand. That's why, I have used a big M notation as 10000.
	}

	void add_solution(){
		for (int i=0;i<N;i++) {solutions[sol_counter][i]=sol[i];}
		sol_counter+=1;
	}

	void print_solutions(){
		for (int i=0;i<sol_counter;i++){
			for (int j=0;j<N;j++){
				cout<<solutions[i][j]<<"   ";
			}
			cout<<endl;
		}
	}

	int solve(){
		int calls=0;
		this->allocate_solution();
		int col=0;
		while (col>=0){
			sol[col]+=1;
			if (sol[col]==N){
				sol[col]=-1;
				col-=1;
			}
			else {calls+=1;
			if (this->is_feasible(col)){
				if (col==N-1) {
					this->add_solution();
				}
				else {
					col+=1;
				}
			}
			}

		}
		return calls;
	}

};

int main(){

	N_Quenn d(8);
	int k = d.solve();
	cout<<k<<endl;
	d.print_solutions();

}

// The algorithm can be seen as a Depth-First Search.
// This algorithm uses back-tracking. 
// This algorithm is deterministic. It is out of probabilitistic concept.
// Computational completixy of the program is upper bounded by O(N!).



