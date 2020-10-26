#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;


class Field{
    string cult;
    unsigned int quantity;
    unsigned int slave_count;
public:
    Field(string cult, unsigned int quantity, unsigned int slave_count){
        this->cult = cult;
        this->quantity = quantity;
        this->slave_count = slave_count;
    }
    
    // get class atributes
    string get_cult(){
        return this->cult;
    }
    unsigned int get_quantity(){
        return this->quantity;
    }
    unsigned int get_slave_count(){
        return this->slave_count;
    }
    
    //set class atributes
    void set_cult(string cult){
        this->cult = cult;
    }
    void set_quantity(unsigned int quantity){
        this->quantity = quantity;
    }
    void set_slave_count(unsigned int slave_count){
        this->slave_count = slave_count;
    }
    
};

class Farm{
    list<Field> fields;
    string name;
    unsigned int slaves;
public:
    Farm(list<Field> curr_list, string name, unsigned int slaves){
        this->fields = curr_list;
        this->slaves = slaves;
        this->name = name;
    }
    // add field to fields
    void add_field(Field field) {
        fields.push_back(field);
    }
    
    //remove field from fields
    /*void remove_fields(Field field){
        fields.remove(field);
    }*/
    
    int get_production(string type){
        // get all quantities from list which culture is type
        
        if (fields.empty()){
            throw "No fields found";
        }
        bool is_in = false;
        unsigned int curr_q = 0;
        for (list <Field>::iterator it = fields.begin(); it != fields.end() ; it++) {
            Field curr_f = *it;
            if (curr_f.get_cult() == type){
                is_in = true;
                if (curr_f.get_slave_count() <= slaves){
                    slaves -= curr_f.get_slave_count();
                    curr_q += curr_f.get_quantity();
                }
            }
        }
        if (is_in == false){
            throw "Type of production didn't found";
        }
        return curr_q;
    }
    
    // get class atributes
    list<Field> get_fields(){
        return this->fields;
    }
    
    string get_name(){
        return this->name;
    }
    
    unsigned int get_slaves(){
        return this->slaves;
    }
    
    //set class atributes
    void set_field(list<Field> curr_fields){
        this->fields = curr_fields;
    }
    
    void set_name(string name){
        this->name = name;
    }
    
    void set_slaves(unsigned int slaves){
        this->slaves = slaves;
    }
    // Get data from file
    //ofstream out = ofstream("farm.txt");
    
    
};
int main()
{
    list <Field> fields;
    
    //Enter field parameters and adding to field tolist 
    cout << "Enter Field parameters or stop" << endl;
    while (true){
        string cult;
        unsigned int quantity;
        unsigned int slave_count;
        cout << "Enter culture or stop" << endl;
        cin >> cult;
        if (cult == "stop"){
            break;
        }
        cout << "Enter quantity" << endl;
        cin >> quantity;
        cout << "Enter slave count" << endl;
        cin >> slave_count;
        Field curr_f = Field(cult, quantity, slave_count);
        fields.push_back(curr_f);
    }
    
    Farm farm = Farm(fields, "nai dobrat firma", 23);
    string wanted_cult;

    // get culture
    cout << "Enter culture to see the get the production" << endl;
    cin >> wanted_cult;
    
    // Get quantity of current culture
    unsigned int result = 0;
    try{
        cout << wanted_cult << "production is:  " << farm.get_production(wanted_cult) << endl;
    }catch(const char * ex){
       	cerr<<ex<<endl;
    }
    
    for (list<Field>::iterator it = fields.begin(); it != fields.end(); it++) {
        Field field = *it;
        cout << field.get_cult()<< " : " << field.get_quantity() << " : " << field.get_slave_count() << endl; 
    }


    return 0;
}

