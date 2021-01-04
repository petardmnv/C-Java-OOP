#include <iostream>
#include <string>
#include "bill.cpp"
using namespace std;

class Payment: public Bills{
public:
	Payment(double b): Bills(b)
	{

	}
	double pay(double money){
		if (money < get_bill()){
			throw "Not enough money!";
		}
		money -= get_bill();
		return money;
	}
	
};



int main(int argc, char const *argv[])
{
	Payment peho = Payment(12.02);
	double first_wallet = 10.2;
	double second_wallet = 2000;
	double result = 0;
	try{
		result = peho.pay(first_wallet);
	}catch(char* exception){
		cout << exception << endl;
	}
	return 0;
}