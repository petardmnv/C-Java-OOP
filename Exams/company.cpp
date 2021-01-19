#include <iostream>
#include <string>
#include <vector>
#include <list>

/*#include <mine.cpp>
#include <worker.cpp>
#include <NormalWorker.cpp>
#include <GreedyWorker.cpp>
#include <AntisocialWorker.cpp>*/

using namespace std;

class Worker{
	string name;
    unsigned int unique_number;
    unsigned int material;
public:
	Worker(){}
    Worker(string name,unsigned int unique_number,unsigned int material):
        name(name), unique_number(unique_number), material(material){}
    Worker(const Worker& other){
    	this->name = other.getName();
    	this->unique_number = other.getUniqueNumber();
    	this->material = other.getMaterial();
    }

    void print() const {
        cout<<this->name<<endl;
        cout<<this->unique_number<<endl;
        cout<<this->material<<endl;
    }
    string getName() const { return this->name; }
    unsigned int getUniqueNumber() const { return this->unique_number; }
    unsigned int getMaterial() const { return this->material; }
};


class NormalWorker : public Worker{
	
public:
	NormalWorker(string name, unsigned int unique_number): 
	Worker(name, unique_number, 20){}

	int choose_mine(vector<Mine> mines){
    	if(!mines.size()) throw "Bad mine";
    	return 0;
	}
};


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


class Mine{
	unsigned int material;
	unsigned int id;
	vector<Worker> workers;
public:
	Mine(){}
	Mine(unsigned int material, unsigned int id, vector<Worker> workers){
		this->material = material;
		this->id = id;
		this->workers = workers;
	}
	unsigned int getMaterial() const { return this->material; }
	unsigned int getId() const { return this->id; }
	vector<Worker> getWorkers() const { return this->workers; }
	void add_worker(Worker worker){
		this->workers.push_back(worker);
	}

};

class Company{
	string name;
	unsigned int current_material;
	vector<Worker> workers;
	vector<Mine> mines;
public:
	Company(){}
	Company(string name, unsigned int current_material, vector<Worker> workers, vector<Mine> mines) {
		this->name = name;
		this->current_material = current_material;
		this->workers = workers;
		this->mines = mines;
	}
	void mine(){
		for (int i = 0; i < this->workers.size(); ++i){
			try{
				int current mine = this->workers[i].choose_mine(mines);
			}catch(const char* error){
				
			}
		}
	}
};
int main(int argc, char const *argv[]){
	return 0;
}
