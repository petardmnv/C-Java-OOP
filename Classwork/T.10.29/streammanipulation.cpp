#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main(){
	ofstream ostream;
	ostream.open("manipulation.txt");
	ostream << boolalpha << true << endl;
	
	ostream << scientific << 12.34354566 << endl;
	
	ostream << setw(5) << setfill('#') << 23 << endl;
	
	ostream.close();
}
