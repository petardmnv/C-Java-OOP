#include "server.h"
using namespace std;

	Server::Server(){}

	void Server::findByTitle(string title){
		int found_torrents = 0;
		for (int i = 0; i < this->game_torrents.size(); ++i){
			if (title == game_torrents[i]->getTitle()){
				cout << game_torrents[i]->toString() << endl;
				found_torrents += 1;
			}
		}
		for (int i = 0; i < this->film_torrents.size(); ++i){
			if (title == film_torrents[i]->getTitle()){
				cout << film_torrents[i]->toString() << endl;
				found_torrents += 1;
			}
		}
		for (int i = 0; i < this->software_torrents.size(); ++i){
			if (title == software_torrents[i]->getTitle()){
				cout << software_torrents[i]->toString() << endl;
				found_torrents += 1;
			}
		}

		if (!found_torrents){
			throw "Didn't found torrents with this title";
		}

	}

	vector<GameTorrent*> Server::findGamesByMAturityRating(char maturity_rating){
		vector<GameTorrent*> found_game_torrents;
		for (int i = 0; i < this->game_torrents.size(); ++i){
			if (game_torrents[i]->getClassType() == "GameTorrent"){
				if (maturity_rating == game_torrents[i]->getMaturityRating()){
					found_game_torrents.push_back(game_torrents[i]);
				}
			}
		}
		if (!found_game_torrents.size()){
			throw "Didn't found game torrents with this maturity rating";
		}
		return found_game_torrents;
	}

	vector<FilmTorrent*> Server::findFilmByDirector(string director_name){
		vector<FilmTorrent*> found_film_torrents;
		for (int i = 0; i < this->film_torrents.size(); ++i){
			if (film_torrents[i]->getClassType() == "FilmTorrent"){
				if (director_name == film_torrents[i]->getDirector()){
					found_film_torrents.push_back(film_torrents[i]);
				}
			}
		}
		if (!found_film_torrents.size()){
			throw "Didn't found film torrents with this director name";
		}
		return found_film_torrents;
	}

	vector<SoftwareTorrent*> Server::findSoftwareByVersion(int major){
		vector<SoftwareTorrent*> found_software_torrents;
		for (int i = 0; i < this->software_torrents.size(); ++i){
			if (software_torrents[i]->getClassType() == "SoftwareTorrent"){
				if (major == software_torrents[i]->getMajor()){
					found_software_torrents.push_back(software_torrents[i]);
				}
			}
		}
		if (!found_software_torrents.size()){
			throw "Didn't found software torrents with this major";
		}
		return found_software_torrents;
	}