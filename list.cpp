#include <list>
#include <iostream>

using namespace std;

void print(list<int> l){
	for (list<int>::iterator it = l.begin(); it != l.end(); it++){
		cout<<*it<<endl;
	}
}
int main(){
	list<int> l;
	
	for(int i = 0; i < 10; i++){
		l.push_back(i);
	} 
	l.push_front(-2);
	
	print(l);
	cout<<endl;
	l.pop_front();
	l.pop_back();
	print(l);
	cout<<endl;
	list<int>::iterator it = l.begin();
	it++;
	l.insert(it, -45);
	print(l);
	
}
