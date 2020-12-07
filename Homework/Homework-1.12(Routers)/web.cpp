#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
using namespace std;
struct route{
	string ip;
	int index;
	int pakages_sent;

};
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
	//Is that ClassVar
	list<route> routing_table;
	static const int max_elements;
	static const int max_hops;
public:
	Router();
	void add_router(const Router& router){
		Router r = router;
		routers.push_back(&r);
	}
	int query_route(const string adress, const int hop_count){
		/*Finding ip adress form list<route> compare addres with ip
		returns 1 if current router has the same ip as adress ip
		returns 1 if adress is into routing table adresses
		if adress is not in router's routing_table then start 
		searching for ardess into his neighbours vector<Router>. 
		Every neighbour asked = hop_count -= 1
		if one of the neighbour returns 1 add adress to 
		routing_table with index = current neighbour index
		if noone returns 1 return 0*/
		int hops = 0;
		if (this->ip == adress){
			return 1;
		}

		for (list<route>::iterator it = routing_table.begin(); it != routing_table.end(); ++it){
			route r = *it;
			if (r.ip == adress){
				return 1;
			}
		}
		while(hops <= hop_count){
			int index = 0;
			for (vector<Router*>::iterator it = routers.begin(); it != routers.end(); ++it){
				Router* r = *it;
				if (r->ip == adress){
					route new_r = {adress, index, 0}; 
					routing_table.push_back(new_r);
					return 1;
				}
				index += 1;
			}
			hops += 1;
		}

		return 0;
	}
	
	void send_pakage(){
		
	}
};

int main(int argc, char const *argv[]){
	return 0;
}