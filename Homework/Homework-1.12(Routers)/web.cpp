#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

struct route{
	string ip;
	int index;
	int pakages_sent;

};
class Pakage{
	char* content;
	int content_length;
	string pakage_ip;
	string receiver_ip;
	int id;
	static int counter;
public:
	Pakage(char* content, string ip1, string ip2){
		if (strlen(content) == 0){
			throw("Context is empty.");
		}

		if (ip1 == "0.0.0.0" || ip1 == "127.0.0.0"){
			throw("Incorrect package ip.");
		} 

		if (ip2 == "0.0.0.0" || ip2 == "127.0.0.0"){
			throw("Incorrect receiver ip.");
		} 
		counter++;
		this->id = counter;
		this->content_length = strlen(content);
		this->content = new char[content_length];
		strcpy(this->content, content);
		this->pakage_ip = ip1;
		this->receiver_ip = ip2;
	}


	int validate(){
		if (strlen(content) == this->content_length){
			return 0;
		}
		return 1;
	}

	string get_pakage_ip(){
		return this->pakage_ip;
	}

	string get_receiver_ip(){
		return this->receiver_ip;
	}
	char* get_content(){
		return this->content;
	}
	~Pakage(){
		delete[] content;
		counter--;
	}
	
};

class Router{
	//pakage = package :'(
	string name;
	string ip;
	vector<Router*> routers;
	list<route> routing_table;
	static const int max_elements;
	static const int max_hops;
	int sent_pakages = 0;
public:
	Router(string name, string ip){
		this->name = name;
		this->ip = ip;
 	}
	void add_router(const Router& router){
		Router r = router;
		if (r.ip == "0.0.0.0" || r.ip == "127.0.0.0"){
			throw("Invalid router ip.");
		}
		routers.push_back(&r);
	}
	int query_route(const string address, const int hop_count){
		/*Finding ip address form list<route> compare addres with ip
		returns 1 if current router has the same ip as address ip
		returns 1 if address is into routing table addresses
		if address is not in router's routing_table then start 
		searching for ardess into his neighbours vector<Router>. 
		Every neighbour asked = hop_count -= 1
		if one of the neighbour returns 1 add address to 
		routing_table with index = current neighbour index
		if noone returns 1 return 0

		What is hop???
		Mabye hop is layer_based thing. How deep you can search ip
		*/
		int hops = 0;
		if (this->ip == address){
			return 1;
		}

		for (list<route>::iterator it = routing_table.begin(); it != routing_table.end(); ++it){
			route r = *it;
			if (r.ip == address){
				return 1;
			}
		}
		int curr_hops = hop_count;
		while (curr_hops > 1){
			int index = 0;
			for (vector<Router*>::iterator it = routers.begin(); it != routers.end(); ++it){
				Router* r = *it;
				int state = r->query_route(address, curr_hops - 1);
				if (state == 1){
					route new_r = {address, index, 0}; 
					if (routing_table.size() == max_elements){
						this->add_id_at_the_end(new_r);
					}
					return 1;
				}
				index += 1;
			}
			curr_hops -= 1;
		}

		return 0;
	}
	
	void send_pakage(const Pakage& pakage){
		/*check for exeptions - pakage content is null or
		empty and pakage i
		if receiver_id == Router ip OK
		if receiver_id in routing_table => pakages_sent += 1
		send_pakage is called in next router
		else search in query_route with hop_count = Max_hops
		found noting -> break and print massage*/
		Pakage p = pakage;
		char* pakage_content = p.get_content();
		string pakage_receiver_ip = p.get_receiver_ip();
		if (strlen(pakage_content) == 0){
			throw("Incorrect pakage content");
		}
		if (pakage_receiver_ip == "127.0.0.0" || pakage_receiver_ip == "0.0.0.0"){
			throw("Incorrect pakage receive ip");
		}

		if (pakage_receiver_ip == this->ip){
			cout << "OK. Pakage with ip - " << pakage_receiver_ip << " - sent." << endl;
			sent_pakages += 1;
			return;
		}
		for (list<route>::iterator it = routing_table.begin(); it != routing_table.end(); ++it){
			route r = *it;
			if (r.ip == pakage_receiver_ip){
				r.pakages_sent += 1;
				sent_pakages += 1;
				if (sent_pakages % 10 == 0){
					this->sorting_routing_table();
				}
				cout <<  "Sent pakage with ip - " << pakage_receiver_ip << "to neighbour router."  << endl;
				routers.at(r.index)->send_pakage(pakage);
				return;
			}
		}
		int is_in = query_route(pakage_receiver_ip, max_hops);	
		if (is_in == 0){
			cout << "Failed. Didn't found router with ip - " << pakage_receiver_ip << " - ." << endl;
			return;
		}else{
			this->send_pakage(pakage);
		}

	}
	void sorting_routing_table(){
		if (sent_pakages == 10){
			for (list<route>::iterator it1 = routing_table.begin(); it1 != routing_table.end(); ++it1){
				for (list<route>::iterator it2 = it1++; it2 != routing_table.end(); ++it2){
					if (it1->pakages_sent < it2->pakages_sent){
						route r = *it1;
						*it1 = *it2;
						*it2 = r;
					}
				}
			}
		}
	}

	void add_id_at_the_end(route r){
		routing_table.pop_back();
		routing_table.push_back(r);

	}
	~Router(){}
};

int Pakage::counter = 0;
const int Router::max_elements = 15;
const int Router::max_hops = 3;

vector<Router*> write_elements_in_vector(string file){
	vector<Router*> routers;
	ifstream myfile;
	myfile.open(file);
	string word;
	while (myfile >> word){
		Router *router = new Router(currName, currIp);
	}

}

void make_connections(vector<Router*> routers, string file){
	ifstream myfile;
	myfile.open(file);
}
int main(int argc, char const *argv[]){
	return 0;
}