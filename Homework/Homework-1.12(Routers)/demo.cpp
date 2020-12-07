#include <iostream>
#include <string.h>

using namespace std;

class A
{
	int a, b;
public:
	A(int a, int b){
		this->a = a;
		this->b = b;
	}
	void get_new(const A &new_a){
		A c = new_a;
		cout << c.a << c.b << endl;

	}
	void print_class(){
		cout << this->a << this->b << endl; 
	}
	
};

int main(){
	A a = A(1, 2);
	A b = A(3, 4);
	a.get_new(b);
    return 0;
}
