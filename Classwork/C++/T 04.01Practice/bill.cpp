#include <iostream>
#include <string>
using namespace std;

class Bills{
	double bill;
	virtual double pay(double money);
public:
	explicit
	Bills(double b) : bill(b){}
	double get_bill() {
		return this->bill;
	}
};