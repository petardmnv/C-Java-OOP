#include <iostream>
#include <string>
#include <vector>
#include <list>

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

