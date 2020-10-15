#include <iostream>
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
	void getName(string name){
		this->name = name;
	}
	void getQuantity(int quantity){
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
	Product* produced_products;
	Factory(Product *produced_products){
		this->produced_products = produced_products;
	}
	
};

int main(){
	queue<Order> orders;
	list<Factory> factories;
	queue<Order> fin_or;
	queue<Order> unfin_or;
	string pr_name;
	int pr_quantity;
	
	
	while (true){
		cin>>pr_name;
		if (pr_name == "stop"){
			break;
		}
		cin>>pr_quantity;
		Product curr_pr = Product();
		curr_pr.getName(pr_name);
		curr_pr.getQuantity(pr_quantity);
		Order curr_or = Order(curr_pr, false);
		orders.push(curr_or);
	}

	
	Product products[2];
	products[0].getName("comp");
	products[0].getQuantity(15); 
	products[1].getName("kartof");
	products[1].getQuantity(15);
	Factory first_factory = Factory(products);	
	factories.front(first_factory);
	products[0].getName("mishka");
	products[0].getQuantity(10); 
	products[1].getName("kartof");
	products[1].getQuantity(15);
	Factory second_factory = Factory(products);
	factories.front(second_factory);	
	
	//cout<<"Size:"<<sizeof(factories.front()) / sizeof(Product)<<endl;
			
	while (orders.size() > 0){
		for (list<Factory>::iterator it = factories.begin(); it != factories.end(); it++){
			if (orders.front().product.name == *it.produced_products[0].name){
				orders.front().set_is_completed(true);
			}
			else if (orders.front().product.name == *it.produced_products[1].name){
				orders.front().set_is_completed(true);
			}
		} 
		if (orders.front().is_completed){
			fin_or.push(orders.front());
		}else{
			unfin_or.push(orders.front());
		}
		orders.pop();		
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
