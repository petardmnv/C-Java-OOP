#include <manager.h>
#include "iostream"
using std::string;
using std::cout;
using std::endl;

manager::manager();
manager::manager(string name, int id, int level): employee(name, id) {
	this->level = level;
}
int manager::getLevel(){
	return level;
}
void manager::setLevel(int level){
	this->level = level
}

void manager::print(){
	cout << "Name: " << getName() << "Id: " << getId() << "Level: " << getLevel() << endl; 
}