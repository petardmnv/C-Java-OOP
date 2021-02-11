#include "employee.h"
#include "iostream"

using std::string;
using std::cout;
using std::endl;

employee::employee();
employee::employee(string name, int id){
	this->name = name;
	this->id = id;
}
string employee::getName(){
	return name;
}
int employee::getId(){
	return id;
}

void employee::setName(string name){
	this->name = name;
}
void employee::setId(int id){
	this->id = id;
}

void employee::print(){
	cout << this->name << this->id << endl;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}