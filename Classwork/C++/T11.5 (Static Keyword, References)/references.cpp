petar.dmnv@gmail.com
Aetv3?!GHDvse20OP
#include <iostream>
#include <list>
using namespace std;
void swap_pointers(int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
	
	cout << *a << " " << *b << endl;
} 

void swap_references(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
	
	cout << a << " " << b << endl;
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
	House(unsigned int pet_count, unsigned int room_count) : pet_count(pet_count), room_count(room_count){} 
	static void print(const House& h){
	//h.pet_count = 0;
		cout << h.pet_count << " " << h.room_count << " " << h.people.size() << endl; 
	}
	
	unsigned int get_pet_count(){return pet_count;}
};

int main(){
	int a = 4;
	int b = 9;
	
	// pointer = int *p = a; 
	//reference = int &r = a; izpolzvat edin i su6ti adrers => pipa6 li ednata promenliva promenq6 i drugata
	
	swap_references(a, b);
	cout << a << " " << b << endl;
	
	House h1 = House(2, 5);
	House::print(h1);
	cout << h1.get_pet_count() << endl;
	return 0;
}
