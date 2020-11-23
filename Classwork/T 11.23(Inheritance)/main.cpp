#include "employee.h"
#include "manager.h"
#include "iostream"

using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
	employee e = employee("Peho", 1);
	manager m = manager("Cveteto", 2 , 10);
	e.print();
	m.print();
	return 0;
}