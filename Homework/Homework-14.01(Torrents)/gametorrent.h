#ifndef GAMETORRENT_H
#define GAMETORRENT_H
#include <string>
#include <torrent.h>


class GameTorrent : public Torrent{
	string system;
	char maturity_rating;

public:
	GameTorrent(){}
	GameTorrent(string title, int size, string uploader,
		int downloads_count, string system, char maturity_rating) : Torrent(title, size, uploader, downloads_count){}
	GameTorrent(const GameTorrent& t){}

	const string getClassType(){}

	const string toString(){}

	char getMaturityRating() const {}
	string getSystem() const {}
};

#endif