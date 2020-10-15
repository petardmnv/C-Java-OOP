#include <iostream>

using namespace std;

class Strings {
public:
double wight;
    Strings(double wight){
        this->wight = wight;
    }
};
class Giutar{
public:
	Strings string_array[6] = {0,0,0,0,0,0};
    void add_string(int index, Strings my_string){
        if (this->my_string.wight > 6 || my_string.wight < 0.2){
            throw "string wight is not awolled";
            
        }
        for (int i = 0; i < 6; i++) {
            if (i < index){
                if (string_array[i] > string_array[index]){
                    throw "Strings are not increasing";
                }
            }else if(index < i){
                if (string_array[i] == 0){
                    continue;
                }
                if (string_array[i] < string_array[index]){
                    throw "Strings are not increasing";
                }
            }
        }
    }
};

int main()
{
    class Strings my_string;
    my_string.Strings(1);
    class Giutar my_guitar;
    try{
        my_guitar.add_string(1, my_string);
    }catch(const char * ex){
        cout<<ex<<endl;
    }
    my_string.Strings(0.5);
    try{
        my_guitar.add_string(0, my_string);
    }catch(const char * ex){
        cout<<ex<<endl;
    }
    my_string.Strings(3);
        try{
        my_guitar.add_string(, my_string);
    }catch(const char * ex){
        cout<<ex<<endl;
    }
    /*my_string.Strings(4);*/
    
    return 0;
}
