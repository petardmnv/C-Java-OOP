#include <iostream>
#include <string>
#include <vector>

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
	vector<int> asdf;
public:
	B(){}
	B(int a, int b, vector<int> asdf) : A(a, b), asdf(asdf){
		if (asdf.size() == 0){
			throw "Empty vector";
		}
	}
	/*void toString(){
		cout << getA() << ", " <<  getB() << ", " << c << endl; 
	}*/
	//int getC() const { return c; }
	vector<int> getAsdf() const { return this->asdf; }
};

int main(int argc, char const *argv[])
{
	A a = A();
	B b = B();
	vector<int> asdf;
	/*asdf.push_back(12);
	asdf.push_back(22);
	asdf.push_back(23);
	asdf.push_back(24);*/
	try{
		a = A(1 ,23);
		b = B(2, 3, asdf);
		cout << b.getAsdf()[0] << endl;
	}catch(const char* error){
		cout << error << endl;
	}
	/*A new_a = A(a);
	b.toString();

	if ("asdf" == "asf"){
		cout << "ok" << endl;
	}*/
	return 0;
}