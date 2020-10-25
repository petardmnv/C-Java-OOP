#include <iostream>
#include <string>
using namespace std;
#include <queue>
#include <list>

class Product{
public:
	string name;
	int quantity;
	Product(){
		this->name = "";
		this->quantity = 0;
	}
	Product(string name, int quantity){
		this->name = name;
		this->quantity = quantity;
	}
};

class Order{
public:
	Product product;
	bool is_completed;
	Order(Product product, bool is_completed){
		this->product = product;
		this->is_completed = is_completed;
	}
	void set_is_completed(bool is_completed){
		this->is_completed = is_completed;
	}
};
class Factory{
public:
	list <Product> p;
	
	Factory(list <Product> p){
		this->p = p;
	}
	bool is_in_factory(Product o_p){
		for (list <Product>::iterator it = p.begin(); it != p.end(); it++){
			Product curr_p = *it;
			if (curr_p.name == o_p.name){
				return true;
			}
					
		}
		return false;
	}
};

int main(){
	list<Factory> factories;
	
	factories.push_back(
		Factory(
			list<Product>({
	    		Product("apple", 100),
        		Product("peach", 50),
        		Product("banana", 35)
        	})
    	)
    );
    factories.push_back(
    	Factory(
			list<Product>({	
	    		Product("desk", 100),
        		Product("comp", 50),
        		Product("mishka", 35)
        	})
    	)
    );
    
	queue<Order> orders;
	string pr_name;
	int pr_quantity;
	
	while (true){
		cin>>pr_name;
		if (pr_name == "stop"){
			break;
		}
		cin>>pr_quantity;
		Product curr_pr = Product(pr_name, pr_quantity);
		Order curr_or = Order(curr_pr, false);
		orders.push(curr_or);
	}
	
	queue<Order> fin_or;
	queue<Order> unfin_or;
	//Check items and sort them into Finished and Unfinished
	
	while(!orders.empty()){
		Order curr_ord = orders.front();
		orders.pop();
		
		Product curr_p = curr_ord.product;
		for (list <Factory>::iterator it = factories.begin(); it != factories.end(); it++){
			Factory f = *it;
			if (f.is_in_factory(curr_p)){
				curr_ord.set_is_completed(true);
			}	
		}
		if (curr_ord.is_completed){
			fin_or.push(curr_ord);
		}
		else {
			unfin_or.push(curr_ord);
		}
	}
	
	cout<<"Finished orders"<<endl;
	while (fin_or.size() > 0){
		cout<<fin_or.front().product.name<<endl;
		fin_or.pop();
	}
	
	cout<<"Unfinished orders"<<endl;
	while (unfin_or.size() > 0){
		cout<<unfin_or.front().product.name<<endl;
		unfin_or.pop();
	}		
			
			
			
}
