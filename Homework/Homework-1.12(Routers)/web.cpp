#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class WebPack{
	char* content;
	int content_length;
	string from_ip;
	string to_ip;
	int id;
	int counter = 0;
public:
	WebPack(char* content, string ip1, string ip2){
		if (strlen(content) == 0 || content == NULL){
			throw("Context is empty.");
		}

		if (ip1 == "0.0.0.0" || ip1 == "127.0.0.0"){
			throw("Incorrect IP.");
		} 

		if (ip2 == "0.0.0.0" || ip2 == "127.0.0.0"){
			throw("Incorrect IP.");
		} 
		counter++;
		this->id = counter;
		this->content_length = strlen(content);
		this->content = new char[content_length];
		strcpy(this->content, content);
		this->from_ip = ip1;
		this->to_ip = ip2;
	}


	int validate(){
		if (strlen(content) == this->content_length){
			return 0;
		}
		return 1;
	}


	~WebPack(){
		delete[] content;
		counter--;
	}
	
};

class Router{
	string name;
	string ip;
	vector<Router*> routers;
	#todo 
	//class attributes and functionality
public:
	Router();
	~Router();
	
};

int main(int argc, char const *argv[]){
	return 0;
}