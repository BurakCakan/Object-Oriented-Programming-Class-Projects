/*
$ g++ hw2q1.cpp
Burak Çakan - 702201003 - 11.01.2020
In this script, I am taking rect or polar coordinates of a point and converting to each other. 
With opetor overloading, I can also make addition and subtraction operations of these polar and rect coordinates.
*/

#include<iostream>
#include<math.h>

using namespace std;

class Coord{
protected:
	char* origin;
	char* name;
public:
	Coord(): origin(NULL), name(NULL){}
	void set_origin(char* x){
		int arr_size=sizeof(x)/sizeof(x[0]);
		for(int i=0;i<arr_size;i++){origin[i]=x[i];}
	}
	void set_name(char* y){
		int arr_size=sizeof(y)/sizeof(y[0]);
		for(int i=0;i<arr_size;i++){name[i]=y[i];}
	}
	virtual void show(){
		int n=sizeof(this->origin)/sizeof(this->origin[0]);
		int m=sizeof(this->name)/sizeof(this->name[0]);
		cout<<" Origin: "<<endl;
		for(int i=0;i<n;i++){
			cout<<origin[i]<<"   ";
		}
		cout<<endl;
		cout<<" Name: "<<endl;
		for(int i=0;i<m;i++){
			cout<<name[i]<<"   ";
		}
		cout<<endl;
	}
	~Coord(){
		if(origin!=NULL) {
			delete[] origin;}

		if(name!=NULL) {
			delete[] name;}
	}

};

class Rect: public 
 Coord{
public:
	double x;
	double y;
	Rect(): Coord(){};
	Rect(double x_rect, double y_rect): x(x_rect), y(y_rect){};
	void show(){
		cout<<"x value:"<<endl;
		cout<<x<<endl;
		cout<<"y value:"<<endl;
		cout<<y<<endl;
	}

};

class Polar: public 
 Coord{
public:
	double distance;
	double angle;
	Polar(): Coord(){};
	Polar(double dist, double ang): distance(dist), angle(ang){};
	void show(){
		cout<<"distance value:"<<endl;
		cout<<distance<<endl;
		cout<<"angle value:"<<endl;
		cout<<angle<<endl;
	}
	double getx(){
		double x;
		double pi=4*atan(1);
		x=distance*cos(angle*pi/180);
		return x;
	}
	double gety(){
		double y;
		double pi=4*atan(1);
		y=distance*sin(angle*pi/180);
		return y;
	}

};

Rect convert_to_rect(Polar p) {
	double x = p.getx();
	double y = p.gety();
	Rect r = Rect(x,y);
	return r;
}

Polar convert_to_polar(Rect r) {
	double d = pow(pow(r.x,2)+pow(r.y,2),0.5);
	double ang;
	double pi=4*atan(1);
	//double c = pi/180;
	double b = 180/pi;
	if (r.x == 0) {
		if (r.y == 0) {
			ang = 0*b; 
		}
		else if (r.y < 0) {
			ang = -pi/2*b;
		}
		else {
			ang = pi/2*b;
		}
	}
	else if (r.x < 0) {
		if (r.y < 0) {
			ang = (atan(r.y/r.x)-pi)*b;
		}
		else {
			ang = (atan(r.y/r.x)+pi)*b;
		}
	}
	else {
		ang = atan(r.y/r.x)*b;
			}
		

	Polar p = Polar(d,ang);
	return p;
}

const Rect operator + (const Rect& obj1, const Rect& obj2){
	Rect result;
	result.x = obj1.x + obj2.x;
	result.y = obj1.y + obj2.y;
	return result;
}

const Rect operator + (const Rect& obj1, const Polar& obj2){
	Rect result;
	Rect obj3 = convert_to_rect(obj2);
	result.x = obj1.x + obj3.x;
	result.y = obj1.y + obj3.y;
	return result;
}

const Polar operator + (const Polar& obj1, const Rect& obj2){
	Polar result;
	Rect obj3 = convert_to_rect(obj1);
	Rect obj4;
	obj4.x = obj2.x + obj3.x;
	obj4.y = obj2.y + obj3.y;
	result = convert_to_polar(obj4);
	return result;
}

const Polar operator + (const Polar& obj1, const Polar& obj2){
	Polar result;
	Rect obj3 = convert_to_rect(obj1);
	Rect obj4 = convert_to_rect(obj2);
	Rect obj5;
	obj5.x = obj3.x + obj4.x;
	obj5.y = obj3.y + obj4.y;
	result = convert_to_polar(obj5);
	return result;
}

const Rect operator - (const Rect& obj1, const Rect& obj2){
	Rect result;
	result.x = obj1.x - obj2.x;
	result.y = obj1.y - obj2.y;
	return result;
}

const Rect operator - (const Rect& obj1, const Polar& obj2){
	Rect result;
	Rect obj3 = convert_to_rect(obj2);
	result.x = obj1.x - obj3.x;
	result.y = obj1.y - obj3.y;
	return result;
}

const Polar operator - (const Polar& obj1, const Rect& obj2){
	Polar result;
	Rect obj3 = convert_to_rect(obj1);
	Rect obj4;
	obj4.x = obj2.x - obj3.x;
	obj4.y = obj2.y - obj3.y;
	result = convert_to_polar(obj4);
	return result;
}

const Polar operator - (const Polar& obj1, const Polar& obj2){
	Polar result;
	Rect obj3 = convert_to_rect(obj1);
	Rect obj4 = convert_to_rect(obj2);
	Rect obj5;
	obj5.x = obj3.x - obj4.x;
	obj5.y = obj3.y - obj4.y;
	result = convert_to_polar(obj5);
	return result;
}


int main()
{
	// I have tested every case and operator overloading with the commands commented written below:
	//Rect a = Rect(1,1);
	//Rect a = Rect(1,-1);
	//Rect a = Rect(-1,1);
	Rect a = Rect(1,1);
	Polar b;
	b = convert_to_polar(a);
	cout<<b.distance<<endl;
	cout<<b.angle<<endl;

	//Polar c = Polar(1.41421,-135);
	Polar c = Polar(1.41421,-135);
	
/*
	double x = c.getx();
	double y = c.gety();
	cout<<x<<endl;
	cout<<y<<endl;
	Rect d;
	d = convert_to_rect(c);
	cout<<d.x<<endl;
	cout<<d.y<<endl;

	Rect e = a+d;
	cout<<e.x<<endl;
	cout<<e.y<<endl;

	Rect e = a+c;
	cout<<e.x<<endl;
	cout<<e.y<<endl;

	Polar e = c+a;
	cout<<e.angle<<endl;
	cout<<e.distance<<endl;
*/

	Polar e = c+c;
	cout<<e.angle<<endl;
	cout<<e.distance<<endl;

}