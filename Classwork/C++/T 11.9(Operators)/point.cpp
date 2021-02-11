#include <iostream>


using namespace std;

class Point{
	int x;
	int y;
public:
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
	void setX(int x){
		this -> x = x;
	}
	void setY(int y){
		this -> y = y;
	}
	int getX() const{
		return this -> x;
	}
	int getY() const{
		return this -> y;
	}
	
	Point& mul(const int v){
		x *= v;
		y *= v;
		
		return *this;
	}
	Point operator+ (const Point &p){ // Predefinirane na binaren operator
		Point result = Point(x + p.x, p.y + y);
		return result;
	}
	Point operator- (const Point &p){
		Point result = Point(x - p.x, p.y - y);
		return result;
	}
	Point operator- (){
		Point result = Point(-x, -y);
		return result;
	}
	Point operator* (const int val){
		Point result = Point(x * val, y * val);
		return result;
	}

};

Point operator+ (const Point &p1, const Point &p2){
		Point result = Point(p1.getX() + p2.getX(), p1.getY() + p2.getY());
		return result;
	}

ostream& operator<< (ostream& out, const Point &p){
	out << "Point(" << p.getX() << ", " << p.getY() << ")";
	return out;
}

void print(const Point &p){
	cout << p << endl;
}

int main(){
	Point p1 = Point(1, 2);
	Point p2 = Point(3, 4);
	
	Point p3 = p1 + p2;
	p3 = p3*3;
	print(p3);
	Point p4 = -p1;
	print(p4);
	return 0;
}
