#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> s;
	for (int i = 0; i < 10; i++){
		s.push(i);
	}
	s.pop();
	cout<<s.top()<<endl;

}
