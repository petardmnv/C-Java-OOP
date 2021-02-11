#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <typeinfo>
#include <cstdlib>
using namespace std;

class Process{
	int importance;
	double priority;
	double time;
public:
	Process(int importance, double time, double priority){
		this->importance = importance;
		this->time = time;
		this->priority = priority;
	}

    void set_ime(int time) { this->time = time; }
    void set_priority(int priority) { this->priority = priority; }
    int get_importance() const { return importance; }
    double get_time() const { return time; }
    double get_priority() const { return priority; }
};


class FileCopy : public Process{
	int file_count;
	double speed;
public:
	FileCopy(int file_count, double speed){
		Process(4, file_count * speed, speed / 4);
		this->file_count = file_count;
		this->speed = speed;
		//importance has to be const but in main class in normal int
	}
	int get_file_count() const { return file_count; }
	int get_speed() const { return speed; }
};


class AllocateMemory : public Process{
	int wanted_memory;
	int memory;
public:
	AllocateMemory(int wanted_memory, int memory){
		double time = (wanted_memory / memory) * (rand() % 901 + 100);
		Process(7, time, 7 * time * (rand() % 11 + 10));
		this->wanted_memory = wanted_memory;
		this->memory = memory;
	}
	int get_wanted_memory() const { return wanted_memory; }
	int get_memory() const { return memory; }
};


class ProcessManager{
	int threads;
	vector<list<Process>> collection;
public:
	ProcessManager(int threads){
		if (threads < 1){
			throw "invalid threads count";
		}
		this->threads = threads; 
		for(int i = 0; i < threads; ++i){
			list<Process> new_process;
			collection.push_back(new_process);
		}
	}
	void addProcesses(list<Process> processes) {
        int number = processes.size();

        for (unsigned int i = 0; i < number; i++) {
        	//pass
        }
    }
    void print(){
    	int size = collection.size();
    	for(int i = 0; i < size; ++i){
    		cout << "Queue " << i + 1 << " :" << endl;
    		int process_count = 1;
    		std::list<Process>::iterator it;
    		for(it = collection[i].begin(); it != collection[i].end(); ++it){
				//#TODO check class type
    			//string s = typeid(YourClass).name();
    			cout << "Process " << process_count << " :" << endl;
    			cout << "	Importance = " <<it->get_importance() << endl;
    			cout << "	Priority = " <<it->get_priority() << endl;
    			cout << "	Time = " <<it->get_time() << endl;
    			cout << endl;
    			process_count += 1;
    		}
    	}
    }

};


int main(int argc, char const *argv[]){
	/* Ne se kompilira ama tova e ot men za vas 
	za 30 minuti */
	return 0;
}