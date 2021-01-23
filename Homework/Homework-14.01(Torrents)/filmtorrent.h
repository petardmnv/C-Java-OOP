#ifndef FILMTORRENT_H
#define FILMTORRENT_H
#include <string>
#include "torrent.h"
#include <ostream>
#include <sstream>
#include <iostream>
using namespace std;

class FilmTorrent : public Torrent{
	string director;
	int duration;
	string language;
public:
	FilmTorrent();
	FilmTorrent(string title, int size, string uploader,
		int downloads_count, string director, int duration, string language) : Torrent(title, size, uploader, downloads_count), director(director), duration(duration), language(language){
		if (director.size() == 0){
			throw "This director name is invalid.";
		}
		if (duration <= 0){
			throw "This duration is invalid.";
		}
		if (language.size() == 0){
			throw "This language is invalid.";
		}
	}
	FilmTorrent(const FilmTorrent& t): director(t.getDirector()), duration(t.getDuration()), language(t.getLanguage()){}

	const string getClassType();

	const string toString();

	string getDirector() const { return this->director; }
	int getDuration() const { return this->duration; }
	string getLanguage() const { return this->language; }
};

#endif