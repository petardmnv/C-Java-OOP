#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main(){
	string name;
	cout << "Enter your name" << endl;
	getline(cin, name); // vzima celiq red 
	int age;
	cout << "Enter your age" << endl;
	cin >> age;
	
	ofstream ostream;
	ostream.open("test.txt");
	
	ostream << name << endl; // output stream pisane v fail
	ostream << age << endl;
	
	ostream.close();
	
	ifstream  istream; //input stream chetena v fail;
	istream.open("test.txt");
	string file_name;
	getline(istream, file_name);
	
	int file_age;
	istream >> file_age;
	
	istream.close();
	
	cout << "Your name:  " << file_name << endl;
	cout << "Your age:  " << file_age << endl; 
		
}
