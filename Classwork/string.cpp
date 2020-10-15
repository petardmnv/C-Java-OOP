#include <iostream>
#include <string>
using namespace std;

int main(){
	string s = "vrachev";
	string t = " debelachev";
	cout<<s<<endl;
	cout<<t<<endl;
	cout<<s.length()<<endl;
	cout<<s + t<<endl;
	cout<<s.append(t)<<endl;
	string ugly_man;
	cout<<"Enter ugly man"<<endl;
	// cin>>ugly_man // vzima samo purviq element ot reda koito si zapisal v terminala pr Iv ivanov => ugly_man = iv;
	getline(cin, ugly_man); // vzima inputa na celiq red  in input => ugly_man = in input
	cout<<ugly_man;
	
}
