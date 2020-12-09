#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	ifstream myfile;
	myfile.open("t.txt");
	string word;
	while (myfile >> word){
		string name = word;
		myfile >> word;
		string ip = word;
		myfile >> word;
		string content = word;
		cout << "Name " << name << " IP " << ip << "CONTENT -" << content << endl;
		//Router *router = new Router(currName, currIp);
	}
    return 0;
}
