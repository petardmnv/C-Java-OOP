#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <worker.cpp>


using namespace std;


class NormalWorker : public Worker{
	
public:
	NormalWorker(string name, unsigned int unique_number): 
	Worker(name, unique_number, 20){}

	int choose_mine(vector<Mine> mines){
    	if(!mines.size()) throw "Bad mine";
    	return 0;
	}
};

