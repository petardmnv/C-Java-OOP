#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

class Point{
	int x;
	int y;
public:
	Point() {}
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getX() const { return x; }
	int getY() const { return y; }

};


class VectorPoint : public Point{
	double power;
public:
	VectorPoint() {}
	VectorPoint(int x, int y , double power) : Point(x, y){
		this->power = power;
	}
	double getPower() const { return this->power; }
};

class Ball{
	double radius;
	Point starting_point = Point();
	Point current_point = Point();
public:
	Ball() {}
	Ball(Point starting_point, double radius){
		if (radius < 0){
			throw "Invalid radius";
		}
		this->starting_point = starting_point;
		this->current_point = starting_point;
		/*this->starting_point->setX(starting_point.getX());
		this->starting_point->setY(starting_point.getY());
		this->current_point->setX(starting_point.getX());
		this->current_point->setY(starting_point.getY());*/
		this->radius = radius;
	}
	Point getStartingPoint() const { return this->starting_point; }
	Point getCurrentPoint() const { return this->current_point; }
	double getRadius() const { return this->radius; }
	void change_position(int x, int y){
		this->current_point.setX(x);
		this->current_point.setY(y);
	}
};

class Pool{
	Ball ball = Ball();
	vector<Point> points;
	int long_side;
	int short_side;
public:
	Pool(vector <Point> vector_points, Ball ball){
		this->ball = ball;
		for (int i = 0; i < vector_points.size(); ++i){
			this->points.push_back(vector_points[i]);
		}
		this->short_side = 0;
		this->long_side = 0;
	}
	void setPoint(Point point, int position) { this->points[position] = point; }
	void setBall(Ball ball) { this->ball = ball; }
	Point getPoint(int position) const { return this->points[position]; }
	Ball getBall() const { return this->ball; }

	int setSide(int x1, int x2){
		return abs(x1 - x2);
	}
	void find_sides(){
		if (this->points.size() == 2){
			int	first_side = setSide(this->points[0].getX(), this->points[1].getX());
			int second_side = setSide(this->points[0].getY(), this->points[1].getY());
			if (first_side > second_side){
				this->long_side = first_side;
				this->short_side = second_side;
			}else {
				this->long_side = second_side;
				this->short_side = first_side;
			}
		}else{
			int	first_side = setSide(this->points[0].getX(), this->points[2].getX());
			int second_side = setSide(this->points[0].getY(), this->points[2].getY());
			if (first_side > second_side){
				this->long_side = first_side;
				this->short_side = second_side;
			}else {
				this->long_side = second_side;
				this->short_side = first_side;
			}
		}
	 }

	 int check_if_new_position_is_in_rectangle(int x, int y){
	 	return 1;
	 }

	 void hit_the_ball(VectorPoint vector_point){
	 	find_sides();
	 	double max_vector_length_range = this->long_side*3/10;
	 	double min_vector_length_range = this->long_side/10;

	 	double a = abs(this->ball.getCurrentPoint().getX() - vector_point.getX());
	 	double b = abs(this->ball.getCurrentPoint().getY() - vector_point.getY());
	 	double vector_length = sqrt((a * a) + (b * b));
	 	if ((vector_length < min_vector_length_range) || (vector_length > max_vector_length_range)){
	 		throw "Vector length is incorrect.";
	 	}
	 	int new_x = (vector_point.getX() - this->ball.getCurrentPoint().getX())*vector_point.getPower() + this->ball.getCurrentPoint().getX();
	 	int new_y = (vector_point.getY() - this->ball.getCurrentPoint().getY())*vector_point.getPower() + this->ball.getCurrentPoint().getY();
	 	if (check_if_new_position_is_in_rectangle(new_x, new_y)){
	 		ball.change_position(new_x, new_y);
	 		cout << new_x << ":" << new_y << endl;
	 	}
	}
};

vector <Point> get_pool_coordinates(string filepath){
	int coordinates[8], j = 0;
	size_t idx = 0;
	vector<Point> points;
	ifstream file(filepath);
	string text;
	while(getline(file, text, ' ')){
		istringstream is(text);
		string word;
		while(getline(is, word, ':')){
			coordinates[j++] = stoi(word, &idx);
		}
	}
	for (int i = 0; i < j; ++i){
		Point p = Point(coordinates[i], coordinates[i + 1]);
		points.push_back(p);
	}
	return points;
}

int main(int argc, char const *argv[]){
	vector<Point> points = get_pool_coordinates("input2.txt");

	ifstream file("input.txt");
	string word;

	file >> word;
	size_t idx = 0;
	double diameter = stod(word, &idx);

	file >> word;
	int x = stoi(word, &idx);

	file >> word;
	int y = stoi(word, &idx);


	double power;
	int x1, y1;
	cout << "Input ball power and direction point." << endl;
	cin >> power >> x1 >> y1;
	while (power < 2 || power > 5){
		cout << "Invalid power size. Input power: ";
		cin >> power;
	}

	Point p1 = Point(x, y);
	VectorPoint p2 = VectorPoint(x1, y1, power);
	Ball b = Ball(p1, diameter / 2);
	Pool pool = Pool(points, b);
	// (dirX-posX)*2 + posx
	pool.hit_the_ball(p2);
	return 0;

}
/*Изисквания към задачата:
Силата на удара трябва да е число с плаваща запетая между 2 и 5.
Посоката се определя от подадена точка (както виждаме в примера горе, нашата посока се определя от точката с координати (230,130).)
Дължината на получения вектор от топчето до тази точка трябва да е съобразена 
с големината на полето - трябва да има дължина между W/10 и W*3/10, където W е по-голямата страна на на полето. 
Пример: ако W = 320, големината на вектора е в интервала [32, 96]
При удар в ъгъла, координатите на топчето се връщат към началните (от файла)
Полето да бъде описано от точки, образуващи правоъгълник. Пример1: Поле с координати (0,0) и (320,160) ; 
Пример2: Поле с координати (20, 10), (120, 110), (70, 160) и (-30, 60); 


Примерни вход и изход:
* Полето има координати (0,0); (320, 0); (320, 160); (0, 160)
Пример 1: в случай, че топчето ни е в позиция (280,70)
Вход:
 2     230      110   
Изход:
180   150

Пример 2: в случай, че топчето ни е в позиция (300,60)
Вход:
3     250     30  
Изход:
    The ball bounced into the wall  (200, 0)
150  30
Заб: В примера диаметъра на топчето е 0. Ако топчето има диаметър 10 (радиус 5), ще се удари в стената при координати (208.3333333,5) и ще приключи в (150,40).
Пример 3: в случай, че топчето ни е в позиция (230,50)
Вход:
2     200     20  
Изход:
The ball bounced into the wall  (180, 0)
170  10
Заб: В примера диаметъра на топчето е 0. Ако топчето има диаметър 10 (радиус 5), ще се удари в стената при координати (185,5) и ще приключи в (170,20 ).

** Полето има координати (20, 10); (120, 110); (70, 160) и (-30, 60)
Пример 4: в случай, че топчето ни е в позиция (60,80)
Вход:
2     50     50  
Изход:
    The ball bounced into the wall (45,35)
30  30
Заб: В примера диаметъра на топчето е 0. Ако топчето има диаметър 14.14213562373095 (102), ще се удари в стената при координати (50,50) и трябва да се изчислят новите изходни координати.


Други изисквания: 
решението да е на C++ (или C)
ако решението ви е в повече от един файл, архивирайте (zip или rar, молим) го и кръстете архива {№}_{LN}_{FN}, където №  е номер,  LN - фамилия, а FN е първо име.
Оценяване(2-6):
    0-0.5:  Преместване на топче по дадена посока
    0-0.5:  Движение на дадено топче по дадена посока и сила
    0-0.5: Ограничаване на параметрите спрямо посочените по-горе изисквания. Изкарвайте съответно съобщение, ако ударът е невалиден.
    0-1: Отблъскване на топчето в полето - тук въвеждаме полето като фактор, т.е. до сега приемаме, че не е съществувало
    0-1: Отблъскване на топчето в полето, където страните на полето са не са успоредни на осите на координатната система
    0-0.5: Качествен код - важи над 4

Бележка: 2.99 е 2

Важно: 
Задача е безкраен цикъл.
Задачата е опростена максимално, т.е. не зависи от тежест на топчето, сила на триене и други външни фактори. Но диаметъра на топчето е фактор!
В задачата съществува само едно топче, т.е. е невъзможно да се блъсне в друго топче.

Въпроси: За въпроси, моля добавяйте коментари към заданието или по email*/