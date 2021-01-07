#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cstdlib>
using namespace std;

int main(int argc, char const *argv[])
{
	int i = 0;
	while (i < 100){
		int number = rand() % 11 + 10;
		cout << number << endl;
		i += 1;
	}
	return 0;
}