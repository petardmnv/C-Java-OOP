#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;

class Worker{
	string name;
    unsigned int unique_number;
    unsigned int material;
public:
	Worker(){}
    Worker(string name,unsigned int unique_number,unsigned int material):
        name(name), unique_number(unique_number), material(material){}
    Worker(const Worker& other){
    	this->name = other.getName();
    	this->unique_number = other.getUniqueNumber();
    	this->material = other.getMaterial();
    }

    void print() const {
        cout<<this->name<<endl;
        cout<<this->unique_number<<endl;
        cout<<this->material<<endl;
    }
    string getName() const { return this->name; }
    unsigned int getUniqueNumber() const { return this->unique_number; }
    unsigned int getMaterial() const { return this->material; }
};
