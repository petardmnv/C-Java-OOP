#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <worker>
#include<mine>

using namespace std;
class GreedyWorker : public Worker{
	
public:
	GreedyWorker(string name, unsigned int unique_number): 
	Worker(name, unique_number, 25){}

	int choose_mine(vector<Mine> mines){
    	if(!mines.size()) throw "Bad mine";
    	int max_mats=0;
    	int mine_id;
    	for(int i=0; i<mines.size();i++){
        	if(mines[i].getMaterial() > max_mats){
            	max_mats=mines[i].getMaterial();
            	mine_id = i;
        	}
    	}
    	return mine_id;
	}
};
