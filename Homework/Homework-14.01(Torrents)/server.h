#ifndef SERVER_H
#define SERVER_H
#include <vector>
#include <string>
#include "torrent.h"
#include "gametorrent.h"
#include "filmtorrent.h"
#include "softwaretorrent.h"
#include <ostream>
#include <sstream>
#include <iostream>
using namespace std;

class Server{
	vector<GameTorrent*> game_torrents;
	vector<FilmTorrent*> film_torrents;
	vector<SoftwareTorrent*> software_torrents;
	vector<string> usernames;
public:
	Server();
	Server(vector<GameTorrent*> game_torrents, vector<FilmTorrent*> film_torrents, vector<SoftwareTorrent*> software_torrents, vector<string> usernames) : game_torrents(game_torrents), film_torrents(film_torrents), software_torrents(software_torrents), usernames(usernames){
		// Lmao that is working somehow
		if (game_torrents.size() == 0){
			throw "Empty game torrents vector.";
		}
		if (film_torrents.size() == 0){
			throw "Empty film torrents vector.";
		}
		if (software_torrents.size() == 0){
			throw "Empty software torrents vector.";
		}

		if (usernames.size() == 0){
			throw "Empty username vector.";
		}
	} 

	void findByTitle(string title);

	vector<GameTorrent*> findGamesByMAturityRating(char maturity_rating);

	vector<FilmTorrent*> findFilmByDirector(string director_name);

	vector<SoftwareTorrent*> findSoftwareByVersion(int major);

};

#endif