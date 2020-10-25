#include <iostream>
#include <cmath>

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
	Strings string_array[6] = {0, 0, 0, 0, 0, 0};
    void add_string(int index, Strings my_string){
        if (my_string.wight > 6 || my_string.wight < 0.2){
            throw "string wight is not awolled";
            
        }
        for (int i = 1; i < 5; i++) {
			/*if (string_array[i] ==0){
				continue;
			}
			if (string_array[i] > string_array[i - 1]){
				throw "Strings are not increasing";
			}
			if (string_array[i] < string_array[i + 1]){
				throw "Strings are not increasing";
			}*/
            if (i < index){
                if (string_array[i].wight > my_string.wight){
                    throw "Strings are not increasing";
                }
            }else if(index < i){
                if (string_array[i].wight == 0){
                    continue;
                }
                if (string_array[i].wight < my_string.wight){
                    throw "Strings are not increasing";
                }
            }
        }
        this->string_array[index] = my_string;
    }
};

int main()
{
    Giutar my_guitar;
    for (int i = 0; i < 6; ++i){
    	Strings s(i + pow(-1.23, i));
    	try{
       		my_guitar.add_string(i, s);
    	}catch(const char * ex){
       		cerr<<ex<<endl;
    	}
    }
    for (int i = 0; i < 6; ++i){
    	cout << my_guitar.string_array[i].wight << endl;
    }
    return 0;
}
