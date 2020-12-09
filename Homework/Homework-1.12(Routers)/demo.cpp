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
		cout << "Name " << name << " IP " << ip << endl;
		//Router *router = new Router(currName, currIp);
	}
    return 0;
}
