#include <iostream>
#include <list>
#include <string>
#include <iterator>

using namespace std;


//ZNA4I POLOJENIETO E PLA4EVNO ZA SEGA NO 6TE Q ZAVUR^6A
class ClassRoom{
    public:
    list<int> student_id;	
public:
	ClassRoom(list<int> ids){
		this->student_id = ids;
	}
	ClassRoom(){
	    
	}
	//Tuka ne sum sigiuren kakvo se pavi
	list<int> operator+ (int id){
	    list <int> new_list;
	    new_list.push_back(id);
	    return new_list;
	}
	void operator+= (int id){
	    this->student_id.push_back(id);
	}
	//p - 5 = pop_front * 5
    list<int> operator- (int pop_times){
        list<int> removed_elements;
        while(pop_times > 0){
            removed_elements.push_back(this->student_id.front(id));
            this->student_id.pop_front(id);
            pop_times -= 1;
        }
	    return removed_elements;
	}
	int operator-= (const ClassRoom &c){
	    int result = c.student_id.front();
	    c.student_id.pop_front();
	    return result;
	}
	ClassRoom operator[] (int index){
	    int result;
	    if (index > this->student_id.size()){
	        throw "Index out of range"
	    }
	    try{
            list<int>::iterator it = this->student_id.begin();
	        result = advance(it, index);
	        return result;
	    }catch (const char * ex){
       	    cerr << ex << endl;
        }
	}

};
int main(){
    list<int> p;
    int i = 1;
    p.push_back(i++)
    p.push_back(i++)
    p.push_back(i++)
    p.push_back(i++)
	return 0;
}
