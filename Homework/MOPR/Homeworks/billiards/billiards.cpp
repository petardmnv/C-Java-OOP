#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Point{
	int x;
	int y;
public:
	Point(int x, int y){
		this->x = x;
		this->y = y;
	}
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getX() const { return x; }
	int getY() const { return y; }

};

class Ball{
	double radius;
	Point *p;	
public:
	Ball(Point point, double radius){
		if (radius < 0){
			throw "Invalid radius";
		}
		p = &point;
		this->radius = radius;
	}
	Point* getP() const { return p; }
	void change_position(int x, int y){
		p->setX(x);
		p->setY(y);
	}
};

class Pool{
	Ball *ball;
	Point point[4];
public:
	Pool(){
		
	}
};
int main(int argc, char const *argv[])
{
	/*int x, y;
	std::vector<Point> points;
	string text;
	cout << "Pleace enter pool coordinates by pairs like - 120 340 !" << endl;
	for (int i = 0; i < 4; ++i){
		cin >> x >> y;
		Point p = Point(x, y);
		points.push_back(p);
	}
	*/
	/*ifstream file("input.txt");
	string word;
	file >> word;
	size_t idx = 0;
	double power = stod(word, &idx);
	file >> word;
	int x = stoi(word, &idx);
	file >> word;
	int y = stoi(word, &idx);
	cout << power << endl;
	cout << x << endl;
	cout << y << endl;*/
	/*Point p1 = Point(1, 3);
	Ball b = Ball(p1, 12);
	b.change_position(23, 4);
	cout << b.getP()->getX() << endl;
	double power; 
	if (power < 2 || power > 5){
		throw "Invalid power";
	}*/
	// (dirX-posX)*2 + posx
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