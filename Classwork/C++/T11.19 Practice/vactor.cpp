#include<iostream>

using namespace std;
class Vector{
public:
	int size = 0;
	int *array;
	Vector(){
	    this->array = new int [size];
	    
	}
	
	void resize_array(){
   		int* new_arr = new int[size + 1];
   		for(int i = 0; i < size; i++){
        	new_arr[i] = array[i];
   		}
   		size++;
   		array = new_arr;
   		delete[] new_arr;
	}
	
	void add_element(int value){
		resize_array();
		array[size - 1] = value;
	}
	void print(){
		for (int i = 0; i < size; ++i){
			printf("%d\n", array[i]);
		}
	}

};
int main()
{
	Vector vector;
	vector.add_element(1);
	vector.add_element(2);
	vector.add_element(3);
	vector.print();
	return 0;
}
