#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
class employee
{
	std::string name;
	int id;
public:
	employee();
	employee(std::string name, int id);
	std::string getName();
	int getId();
	void setName(std::string);
	void setId(int id);
	void print();
	
};

#endif