#ifndef GAMETORRENT_H
#define GAMETORRENT_H
#include <string>
#include <ostream>
#include <sstream>
#include <iostream>
#include "torrent.h"
using namespace std;


class GameTorrent : public Torrent{
	string system;
	char maturity_rating;

public:
	GameTorrent(){};
	GameTorrent(string title, int size, string uploader,
		int downloads_count, string system, char maturity_rating) : Torrent(title, size, uploader, downloads_count), system(system), maturity_rating(maturity_rating){
		if (maturity_rating != 'E' && maturity_rating != 'M' && maturity_rating != 'P'){
			throw "Invallid maturity_rating value";
		}
		if (system.size() == 0){
			throw "This system name is invalid.";
		}
	}
	GameTorrent(const GameTorrent& t) : maturity_rating(t.getMaturityRating()), system(t.getSystem()){}

	const string getClassType();

	const string toString();

	char getMaturityRating() const { return this->maturity_rating; }
	string getSystem() const { return this->system; }
};

#endif