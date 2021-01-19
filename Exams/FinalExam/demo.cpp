#include <iostream>
#include <string>
#include <vector>
#include <list>


#include <typeinfo>

using namespace std;

class A
{
public:
	A();
	
};

string find_name(A a){
	return typeid(a).name();
}

int main(int argc, char const *argv[])
{
	A a = A();
	cout << find_name(a) << endl;
	return 0;
}