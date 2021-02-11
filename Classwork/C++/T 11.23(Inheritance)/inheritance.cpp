#include "iostream"

using namespace std;


class A
{
	int a = 1;
public:
	int b = 2;
	int getA(){
		return a;
	}
protected:
	int c = 3;
	
};


class B: public A
{
	int d = 4;
public:
	int e = 5;
	void changeC(){
		c = 7;
	}
	int getF(){
		return getA();
	}
	int getC(){
		return c;
	}
	
};
int main(int argc, char const *argv[])
{
	A a;
	B b;
	cout << a.b << endl;
	cout << a.getA() << endl;
	cout << b.e << endl;
	cout << b.getF() << endl;
	cout << b.getC() << endl;
	cout << b.changeC() << endl;
	cout << b.getC() << endl;
	return 0;
}