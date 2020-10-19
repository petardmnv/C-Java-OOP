#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
int main(){
	string data = "Hello";
	data +=  "wordl";
	
	ostringstream ostream;
	ostream << "Hello ";
	ostream << "world " << "KYS" << endl;
	cout << "First str: " << data << endl;
	string str2 = ostream.str();
	cout<peho< "Second string: " << str2;
} 
