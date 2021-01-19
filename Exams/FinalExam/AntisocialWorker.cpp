#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <worker>
#include<mine>

using namespace std;

class AntisocialWorker : public Worker{
	
public:
	AntisocialWorker(string name, unsigned int unique_number): 
	Worker(name, unique_number, 30){}

	int choose_mine(vector<Mine> mines){
    	if(!mines.size()) throw "Bad mine";
    		for(int i=0; i<mines.size();i++){
        		if(mines[i].workers.size()==0)
            		return i;
    	}
    	return -1;
	}
};
