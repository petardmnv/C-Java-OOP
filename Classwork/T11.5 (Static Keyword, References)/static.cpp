#include <iostream>
#include <list>

using namespace std;

int do_some_work(){
	static int counter = 0;
	cout << "Buying bread... " << endl;
	counter++; 
}

class Human{
public:
	string name;
};
class House{
	unsigned int pet_count;
	unsigned int room_count;
	list<Human> people;
public:
	static int instance_count; 
	House(unsigned int pet_count, unsigned int room_count) : pet_count(pet_count), room_count(room_count){
		instance_count ++;
	} 
	static void print(House h){
		cout << h.pet_count << " " << h.room_count << " " << h.people.size() << endl; 
	}
};


int House::instance_count = 0;


class Math{
	Math() {}
public:
	static int add(int a, int b){
		return a + b;
	}
};

namespace Math_v2{
	int add(int a, int b){
		return a + b;
	}
}
int main(){
	int count = 0;
	count = do_some_work();
	count = do_some_work();
	count = do_some_work();
	cout << count << endl; 
	
	House h1 = House(1, 3);
	House::print(h1);
	
	cout << House::instance_count << endl;
	
	cout << Math::add(3, 9) << endl;
	cout << Math_v2::add(3, 9) << endl;
	return 0;
}
