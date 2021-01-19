#include <iostream>
#include <string>

using namespace std;


class A
{
	int a;
	int b;
	virtual void toString(){}
public:
	A(){}
	A(int a, int b){
		if (a < 0 || b < 0){
			throw "Invalid number";
		}
		this->a = a;
		this->b = b;
	}
	A(const A& other){
		this->a = other.getA();
		this->b = other.getB();
	}
	int getA() const { return a; }
	int getB() const { return b; }
};


class B: public A
{
	int c;
public:
	B(){}
	B(int a, int b, int c) : A(a, b){
		if (c < 0){
			throw "Invalid number";
		}
		this->c = c;
	}
	void toString(){
		cout << getA() << ", " <<  getB() << ", " << c << endl; 
	}
	int getC() const { return c; }
};

int main(int argc, char const *argv[])
{
	A a = A();
	B b = B();
	try{
		a = A(1 ,23);
		b = B(2, 3, 12);
	}catch(const char* error){
		cout << error << endl;
	}
	A new_a = A(a);
	b.toString();
	return 0;
}