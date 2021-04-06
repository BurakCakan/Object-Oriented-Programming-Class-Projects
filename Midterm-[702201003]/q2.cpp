#include<iostream>

using namespace std;

class BaseFunc{
protected:
	double* params;
	int N_params;
	int N_x;
public:
	BaseFunc(): N_params(0), params(/*a-1*/NULL) {}
	BaseFunc(int a): N_params(a) {//a-2//
		params = new double [N_params];
	}
	~BaseFunc(){//a-3//
		if(params!=NULL) {
		delete[] params;}
	}

	//b//
	void get_params(double* n){
		for(int i=0;i<N_params;i++){ params[i]=n[i];}
	} 

	void show_params(){
		for(int i=0;i<N_params;i++) cout<<params[i]<<"\t";
		cout<<endl;
	}
	//c//
	virtual double operator () (double* x) = 0;
};

class LinearFunc: public //d// 
 BaseFunc{
public:
	LinearFunc(int n_x): BaseFunc(n_x+1) { int N_x=n_x;}//e//

	//f//
	virtual double operator () (double* x){
		double result=0;

		for (int i=0;i<N_params;i++){

			if(i==0){
					result=params[0];}
			else {
				result=result+params[i]*x[i-1];
			}
			
		}
	return result;
	} 
};

double dummy(BaseFunc* f, double* x) {return (*f)(x);}

int main(int argc, char const *argv[])
{
	LinearFunc f(2);
	double* par=new double[3];
	par[0]=1.2; par[1]=2.1; par[2]=1;
	f.get_params(par);
	double *x=new double[2];
	x[0]=1.0; x[1]=2.4;
	cout<<f(x)<<endl;//right answer=5.7
	cout<<dummy(&f//g// 
	,x)<<endl;//right answer=5.7

	//BaseFunc f2(3); //should not compile
	return 0;
}