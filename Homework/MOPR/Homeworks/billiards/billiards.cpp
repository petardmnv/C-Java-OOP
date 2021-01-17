#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

class Point{
	double x;
	double y;
public:
	Point() {}
	Point(double x, double y){
		this->x = x;
		this->y = y;
	}
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }
	double getX() const { return x; }
	double getY() const { return y; }

};


class VectorPoint : public Point{
	double power;
public:
	VectorPoint() {}
	VectorPoint(double x, double y , double power) : Point(x, y){
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
		this->radius = radius;
	}
	Point getStartingPoint() const { return this->starting_point; }
	Point getCurrentPoint() const { return this->current_point; }
	double getRadius() const { return this->radius; }
	void change_position(double x, double y){
		this->current_point.setX(x);
		this->current_point.setY(y);
	}
};

class Pool{
	Ball ball = Ball();
	vector<Point> points;
	double long_side;
	double short_side;
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

	double setSide(double x1, double x2){
		return abs(x1 - x2);
	}
	void find_sides(){
		// is_two e две ако големината на вектора е 4,
		// защото ми трява първата точка и третата 
		// т.e. points[0] i points[2]
		// Aко големината на вектора е 2 ми трябват
		// points[0] i points[1] т.е is_two ще е 1
		int is_two = 2;
		if (this->points.size() == 2){
			is_two = 1;
		}
		double first_side = setSide(this->points[0].getX(), this->points[is_two].getX());
		double second_side = setSide(this->points[0].getY(), this->points[is_two].getY());

		if (first_side > second_side){
			this->long_side = first_side;
			this->short_side = second_side;
		}else {
			this->long_side = second_side;
			this->short_side = first_side;
		}
	}


	double get_delta_x(double x1, double x2){
		return x2 - x1;
	}
	double get_delta_y(double y1, double y2){
		return y2 - y1;
	}
	double get_angular_coefficient(double delta_x, double delta_y){
		return delta_y / delta_x;
	}
	double get_segment(double angular_coefficient, double x, double y){
		return y - angular_coefficient * x;
	}
	double get_y_using_decart_equation(double new_x, VectorPoint vector_point){
		//Ъгловият коефициент се намира по формулата (y2 - y1) / (x2 - x1)
		double delta_y = get_delta_y(this->ball.getCurrentPoint().getY(), vector_point.getY());
		double delta_x = get_delta_x(this->ball.getCurrentPoint().getX(), vector_point.getX());
		double angular_coefficient = get_angular_coefficient(delta_x, delta_y);
		//Сегмента или отрязъкът могат да бъдат лесно намерени b = y - a*x 
		double segment = get_segment(angular_coefficient, vector_point.getX(), vector_point.getY());
		//След като имам x, ъглов коегициент и отрязък мога да намеря новия y
		return new_x*angular_coefficient + segment;
	}
	double get_x_using_decart_equation(double new_y, VectorPoint vector_point){
		double delta_y = get_delta_y(vector_point.getY(), this->ball.getCurrentPoint().getY());
		double delta_x = get_delta_x(vector_point.getX(), this->ball.getCurrentPoint().getX());
		double angular_coefficient = get_angular_coefficient(delta_x, delta_y);
		double segment = get_segment(angular_coefficient, vector_point.getX(), vector_point.getY());
		return (new_y - segment) / angular_coefficient;
	}

	int check_ball_position(double x, double y){
		// Три случая 
		// 1 - всичко точно няма ядове т.е. топчето не се блъска
		// 2 - Много лошо топчето се е блъснало
		// 3 - Топчето е отишло в някой от ъглите 
		// is_two e две ако големината на вектора е 4,
		// защото ми трява първата точка и третата 
		// т.e. points[0] i points[2]
		// Aко големината на вектора е 2 ми трябват
		// points[0] i points[1] т.е is_two ще е 1

		int is_two = 2;
		if (this->points.size() == 2){
			cout << "wtf" << endl;
			is_two = 1;
		}
		if (x < (this->points[0].getX() + this->ball.getRadius())){
			return -1;
		}
		if (y < (this->points[0].getY() + this->ball.getRadius())){
			return -1;
		}
		if (x > (this->points[is_two].getX() - this->ball.getRadius())){
			return -1;
		}
		if (y > (this->points[is_two].getY() - this->ball.getRadius())){
			return -1;
		}
		// Проверка дали топчето е в ъглите
		if (x == (this->points[0].getX() + this->ball.getRadius()) && y == (this->points[0].getY() + this->ball.getRadius())){
			return 1;
		}		
		if (x == (this->points[is_two].getX() + this->ball.getRadius()) && y == (this->points[0].getY() + this->ball.getRadius())){
			return 2;
		}
		if (x == (this->points[is_two].getX() - this->ball.getRadius()) && y == (this->points[is_two].getY() - this->ball.getRadius())){
			return 3;
		}
		if (x == (this->points[0].getX() - this->ball.getRadius()) && y == (this->points[is_two].getY() -+ this->ball.getRadius())){
			return 4;
		}

	 	return 0;
	 }

	vector<double> get_coordinates_when_ball_hits_the_wall(double x, double y, VectorPoint vector_point){
		vector<double> curr_coordinates;
		//Първо определям коя е страната в която топчето се ударило
		//С помощта на декартовото уравнение мога да намеря то4ката

		// is_two e две ако големината на вектора е 4,
		// защото ми трява първата точка и третата 
		// т.e. points[0] i points[2]
		// Aко големината на вектора е 2 ми трябват
		// points[0] i points[1] т.е is_two ще е 1
		int is_two = 2;
		if (this->points.size() == 2){
			is_two = 1;
		}

		if (x < this->points[0].getX()){
			curr_coordinates.push_back(this->points[0].getX());
			curr_coordinates.push_back(get_y_using_decart_equation(this->points[0].getX(), vector_point));
		}else if (x > this->points[is_two].getX()){
			curr_coordinates.push_back(this->points[is_two].getX());
			curr_coordinates.push_back(get_y_using_decart_equation(this->points[is_two].getX(), vector_point));
		}else if (y < this->points[0].getY()){
			curr_coordinates.push_back(get_x_using_decart_equation(this->points[0].getY(), vector_point));
			curr_coordinates.push_back(this->points[0].getY());
		}else if (y > this->points[is_two].getY()){
			curr_coordinates.push_back(get_x_using_decart_equation(this->points[is_two].getY(), vector_point));
			curr_coordinates.push_back(this->points[is_two].getY());
		}

		return curr_coordinates;
	}

	vector<double> get_coordinates_after_ball_hits_the_wall(double new_x, double new_y, double curr_x, double curr_y){
		vector<double> new_coordinates;
		double x_diversion, y_diversion;
		if (new_x < 0){
			x_diversion = curr_x + new_x;
		}else{
			x_diversion = curr_x - new_x;
		}
		if (new_y){
			y_diversion = curr_y + new_y;
		}else{
			y_diversion = curr_y - new_y;

		}
		new_coordinates.push_back(curr_x - x_diversion);
		new_coordinates.push_back(curr_y - y_diversion);
		return new_coordinates;
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
	 	double new_x = (vector_point.getX() - this->ball.getCurrentPoint().getX())*vector_point.getPower() + this->ball.getCurrentPoint().getX();
	 	double new_y = get_y_using_decart_equation(new_x, vector_point);
	 	int result = check_ball_position(new_x, new_y);
	 	if (result == 0){
	 		ball.change_position(new_x, new_y);
	 		cout << "Ball is in position: " << new_x << " " << new_y << endl;
	 	}else if (result == 1){
	 		ball.change_position(this->ball.getStartingPoint().getX(), this->ball.getStartingPoint().getY());
	 		cout << "Ball hit bottom left corner with coordinates: " << new_x << new_y << endl;
	 		cout << "The ball has been moved to :" << this->ball.getStartingPoint().getX() << " " << this->ball.getStartingPoint().getY() << endl;
	 	}else if (result == 2){
	 		ball.change_position(this->ball.getStartingPoint().getX(), this->ball.getStartingPoint().getY());
	 		cout << "Ball hit bottom right corner with coordinates: " << new_x << new_y << endl;
	 		cout << "The ball has been moved to :" << this->ball.getStartingPoint().getX() << " " << this->ball.getStartingPoint().getY() << endl;
	 	}else if (result == 3){
	 		ball.change_position(this->ball.getStartingPoint().getX(), this->ball.getStartingPoint().getY());
	 		cout << "Ball hit upper right corner with coordinates: " << new_x << new_y << endl;
	 		cout << "The ball has been moved to :" << this->ball.getStartingPoint().getX() << " " << this->ball.getStartingPoint().getY() << endl;
	 	}else if (result == 4){
	 		ball.change_position(this->ball.getStartingPoint().getX(), this->ball.getStartingPoint().getY());
	 		cout << "Ball hit upper left corner with coordinates: " << new_x << new_y << endl;
	 		cout << "The ball has been moved to :" << this->ball.getStartingPoint().getX() << " " << this->ball.getStartingPoint().getY() << endl;
	 	}else if (result == -1){
	 		vector<double> curr_coordinates = get_coordinates_when_ball_hits_the_wall(new_x, new_y, vector_point);
	 		double curr_x = curr_coordinates[0];
	 		double curr_y = curr_coordinates[1];
	 		cout << "The ball bounced into the wall : " << curr_x << ", " << curr_y << endl;
	 		vector<double> new_coordinates = get_coordinates_after_ball_hits_the_wall(new_x, new_y, curr_x, curr_y);
	 		cout << "Ball is in position: " << new_coordinates[0] << ", " << new_coordinates[1] << endl;
	 		ball.change_position(new_coordinates[0], new_coordinates[1]);
	 	}
	}
};

vector <Point> get_pool_coordinates(string filepath){
	double coordinates[8];
	int j = 0;
	size_t idx = 0;
	vector<Point> points;
	ifstream file(filepath);
	string text;
	while(getline(file, text, ' ')){
		istringstream is(text);
		string word;
		while(getline(is, word, ':')){
			coordinates[j++] = stod(word, &idx);
		}
	}
	Point p1 = Point(coordinates[0], coordinates[1]);
	points.push_back(p1);
	Point p2 = Point(coordinates[2], coordinates[3]);
	points.push_back(p2);
	Point p3 = Point(coordinates[4], coordinates[5]);
	points.push_back(p3);
	Point p4 = Point(coordinates[6], coordinates[7]);
	points.push_back(p4);
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
	double x = stod(word, &idx);

	file >> word;
	double y = stod(word, &idx);

	while(1) {
		double power;
		double x1, y1;
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
		pool.hit_the_ball(p2);
	}
	return 0;

}