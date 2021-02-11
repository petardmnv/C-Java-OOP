#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Plane{
	int size;
	int number;
	string model;
	int is_civil;
	int is_military;
	double speed;
	double fuel_amount;
	double loss_per_km;
	float position;
public:

	Plane(int size, int number, string model, int is_civil, int is_military, double speed, double fuel_amount, double loss_per_km, float position){
		this->size = size;
		this->number = number;
		this->model = model;
		this->is_civil = is_civil;
		this->is_military = is_military;
		this->speed = speed;
		this->fuel_amount = fuel_amount;
		this->loss_per_km = loss_per_km;
		this->position = position;
	}

	int getSize() const { return size; }
	int getNumber() const { return number; }
	string getModel() const { return model; }
	int getIsCivil() const { return is_civil; }
	int getIsMilitary() const {return is_military; }
	double getSpeed() const { return speed; }
	double getFuelAmount() const { return fuel_amount; }
	double getLoss() const { return loss_per_km; }
	float getPosition() const { return position; }

	float distance_to_airport(Airport& airport){
		return abs(airport.getPosition() - this->position);
	}

	int can_reach_airport(Airport& airport){
		float distance = distance_to_airport(airport);
		if ((distance * this->loss_per_km) <= this->fuel_amount){
			return 1;
		}
		return 0;
	}

	void land_at_nearest_airport(list<Airport> airports){
		Airport *nearest_airport;
		int nearest_distance = 0;
		for (list<Airport>::iterator it = airports.begin(); it != airports.end(); it++){
			if (can_reach_airport(&it)){
				if (distance_to_airport(&it) >= nearest_distance){
					nearest_distance = distance_to_airport(&it);
					nearest_airport = &it;// Not sure
				}
			}
		}
		nearest_airport->land_plane(this);
	}
};


class CivilPlane: public Plane{
	int passengers;
	int seats;
	int exits;
public:
	CivilPlane(int passengers, int seats, int exits){
		this->passengers = passengers;
		this->seats = seats;
		this->exits = exits;
	}

	int getPassengers() const { return passengers; }
	int getSeats() const { return seats; }
	int getExits() const { return exits; }

};


class CargoPlane : public Plane {
	int current_cargo;
	int max_cargo;
public:
	CargoPlane(int current_cargo, int max_cargo) {
		this->current_cargo = current_cargo;
		this->max_cargo = max_cargo;
	}
};


class WarPlane : public Plane{
	double power;
public:
	WarPlane(double power){
		this->power = power;
	}
};


ostream& operator<<(ostream& os, const Plane& plane){
	if (plane.getIsCivil()){
		os << "  Civil plane" << endl; 
	}else if(plane.getIsMilitary()){
		os << "  Military plane:" << endl; 
	}else {
		os << "  Cargo plane:" << endl;
	}
	os << " Plane size: " << plane.getSize() << endl;
	os << " Plane number: " << plane.getNumber() << endl;
	os << " Plane model: " << plane.getModel() << endl;
	os << " Plane speed: " << plane.getSpeed() << endl;
	os << " Plane fuel amount: " << plane.getFuelAmount() << endl;
	os << " Plane fuel loss per km: " << plane.getLoss() << endl;
	os << " Plane position: " << plane.getPosition() << endl;
	return os;		
}


class Airport{
	int planes_capasity;
	int max_plane_size;
	int civil_airport;
	int military_airport;
	vector<Plane> planes;
	float position;
public:
	Airport(int planes_capasity, int max_plane_size, 
		int civil_airport, int military_airport, 
		vector<Plane> planes, float position){
		this->planes_capasity = planes_capasity;
		this->max_plane_size = max_plane_size;
		this->civil_airport = civil_airport;
		this->military_airport = military_airport;
		for (int i = 0; i < planes.size(); ++i){
			this->planes[i] = planes[i];
		}
		this->position = position;
	}

	int getPlanesCapasity() const { return planes_capasity; }
	int getMaxPlaneSize() const { return max_plane_size; }
	int getIsCivilAirport() const { return civil_airport; }
	int getIsMilitaryAirport() const { return military_airport; }
	vector<Plane> getPlanes() const { return planes; }
	float getPosition() const { return position; }

	int can_fit_plane(const Plane& plane){
		if (this->planes_capasity < (this->planes.size() + 1)){
			return 0;
		}
		if (plane.getSize() > this->max_plane_size){
			return 0;
		}
		if (plane.getIsCivil()){
			if (this->civil_airport == 0){
				return 0;
			}
		}else {
			if (this->military_airport == 0){
				return 0;
			}
		}
		return 1;
	}

	void land_plane(const Plane& plane){
		if (can_fit_plane(plane) == 1){
			this->planes.push_back(plane);
		}else {
			throw "The current plane can't land on this airport!";
		}
	}
};


int main(int argc, char const *argv[]){
	Plane first = Plane(10, 2, "Hello", 1, 0, 10, 15, 20, 23);
	cout << first << endl;
	return 0;
}