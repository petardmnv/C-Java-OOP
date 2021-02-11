#include <iostream>
#include <string>
using namespace std;

class Account{
	string IBAN;
	double money; 
	double get_money(){
		return this->money;
	}
	void set_money(double new_money){
		this->money = new_money;
	}
	string get_IBAN(){
		return this->IBAN;
	}
	void set_IBAN(string new_iban){
		this->IBAN = new_iban;
	}
	Account();
	Account(string iban, double money){
		this->IBAN = iban;
		this->money = money;
	}

};

class User{
	string username;
	double password;

public:
	User();
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}

		