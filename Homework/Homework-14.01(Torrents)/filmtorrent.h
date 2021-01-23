#ifndef FILMTORRENT_H
#define FILMTORRENT_H
#include <string>
#include <torrent.h>

class FilmTorrent : public Torrent{
	string director;
	int duration;
	string language;
public:
	FilmTorrent(){}
	FilmTorrent(string title, int size, string uploader,
		int downloads_count, string director, int duration, string language) : Torrent(title, size, uploader, downloads_count){}
	FilmTorrent(const FilmTorrent& t){}

	const string getClassType(){}

	const string toString(){}

	string getDirector() const {}
	int getDuration() const {}
	string getLanguage() const {}
};

#endif