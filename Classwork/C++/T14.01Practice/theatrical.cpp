#include <iostream>
#include <vector>
#include <exception>

using namespace std;

class Action{

public:

	vector<string> actors_names;
	int number;

	Action(vector<string> actors, int number){
		if(number <= 0 || actors.size() == 0){
			throw exception();
		}
		this->actors_names = actors;
		this->number = number;
	}

	virtual void print() const{
		cout << number << endl;
		for(int i = 0; i < actors_names.size(); i++){
			cout << actors_names[i] << endl;
			if(i != actors_names.size() - 1){
				cout << ", " << endl;
			}
		}
	}
};

class MusicleAction : public Action{

public:
	string song;	

	MusicleAction(string song, vector<string> names, int number) : Action(names, number){
		this->song = song;
	}

	void print() const{
		cout << number << endl;
		for(int i = 0; i < actors_names.size(); i++){
			cout << actors_names[i] << endl;
			if(i != actors_names.size() - 1){
				cout << ", " << endl;
			}	
			cout << endl;
			cout << song << endl;
		}
	}
};

class Musicle{

public:

	string name;
	vector<MusicleAction> actions;

	Musicle(string name, vector<MusicleAction> actions){
		this->name = name;
		this->actions = actions;
	}

	void add_actions(MusicleAction action){
		for(int i = 0; i < actions.size(); i++){
			if(actions[i].number == action.number){
				throw exception();
			}
		}
		actions.push_back(action);
	}

	void print() const{
		cout << name << endl;
		for(int i = 0; i < actions.size(); i++){
			actions[i].print();
		}
	}

	/*void sort(){
	
		for(int i = 0; i < actions.size() - 1; i++){
			for(int j = i + 1; j < actions.size(); i++){
				if(actions[i].number > actions[j].number){
					MusicleAct third = actions[i];
					actions[i] = actions[j];
					actions[j] = third;
				}
			}
		}
	}*/
};

int main(int argc, char const *argv[]){
	return 0;
}
