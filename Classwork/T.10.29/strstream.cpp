#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
int main(){
	string data = "2.134 34 4 end";

	istringstream istream(data);
	
	double p;
	istream >> p;
	
	
	if (istream.good()){
		cout << "This data: " << p << endl;
	}
	else {
		cerr << "Something went wrong." << endl;
	}
	
	int a;
	istream >> a;
	
	
	if (istream.good()){
		cout << "This data: " << a << endl;
	}
	else {
		cerr << "Something went wrong." << endl;
	}
	
	int a1;
	istream >> a1;
	
	
	if (istream.good()){
		cout << "This data: " << a1 << endl;
	}
	else {
		cerr << "Something went wrong." << endl;
	}
}
