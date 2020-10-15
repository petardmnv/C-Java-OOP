#include <vector>
#include <iostream>
using namespace std;
void print(vector<int> curr_v){
	for(int i = 0;i < curr_v.size(); i++){
		cout<<curr_v[i]<<endl;
	}
}

void print_with_iterator(vector<int> v){
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout<<*it<<endl;
	}
}
int main(){
	vector<int> v;
	for(int i = 0;i < 10; i++){
		v.push_back(i);
	}
	print(v);
	cout<<"Capacity"<<v.capacity()<<endl;
	cout<<"Size"<<v.size()<<endl;
	v.pop_back();
	v.pop_back();
	v.pop_back();
	cout<<"Capacity"<<v.capacity()<<endl;
	cout<<"Size"<<v.size()<<endl;
	v.shrink_to_fit();
	cout<<"Capacity"<<v.capacity()<<endl;
	print_with_iterator(v);
}

