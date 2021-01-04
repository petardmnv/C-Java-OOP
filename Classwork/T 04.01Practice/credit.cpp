#include <iostream>
#include <string>
#include "bill.cpp"
using namespace std;

class Credit: public Bills{
	const double credit_limit
public:
	Credit(const double bill, const double credit_limit){
		Bills(bill);
		this->credit_limit = credit_limit;
	}
	double pay(double money){
		if (bill > credit_limit){
			throw "You don't have money in your credition limit";
		}
		credit_limit -= bill;
		credit_limit -= bill * 0.05;
		money += bill;
		return money;
	}
};