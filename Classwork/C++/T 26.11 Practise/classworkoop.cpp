#include "iostream"
using std::endl;
using std::cout;

class Shape
{
public:

	virtual float get_area()const {return 0;};
	virtual float get_perimeter()const {return 0;};
};

class Square: public Shape
{

	float side_one;

public:
    Square(float s){
        side_one = s;
    }
	float get_area() const{
		return side_one * side_one;
	}
	float get_perimeter() const{
		return 4 * side_one;
	}
	void set_side_one(float side){
		this->side_one = side;
	}

};

class Rectangle: public Shape
{

	float side_one;
	float side_two;

public:
    
    Rectangle(float s, float v){
        side_one = s;
        side_two = v;
    }
    
	float get_area() const{
		return side_one * side_two;
	}
	float get_perimeter() const{
		return 2 * (side_one + side_two);
	}
	void set_side_one(float side){
		this->side_one = side;
	}
	void set_side_two(float side){
		this->side_two = side;
	}
};

void print_area_and_shape(const Shape &s){
	cout << "Area: " << s.get_area() << ". Perimeter: " << s.get_perimeter() << ". " << endl;
}

int main(int argc, char const *argv[])
{
	Rectangle rect = Rectangle(3, 4);
	cout << rect.get_perimeter() << endl;
	cout << rect.get_area() << endl;
	print_area_and_shape(rect);
	return 0;
}