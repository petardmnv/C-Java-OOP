#include "softwaretorrent.h"
#include "filmtorrent.h"
#include "gametorrent.h"
#include "server.h"
#include "torrent.h"
#include <ostream>
#include <sstream>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	Server server = Server();
	try{
		GameTorrent game_torrent = GameTorrent("Rust", 120, "Steam", 120000, "Windows", 'M');
		FilmTorrent film_torrent = FilmTorrent("The godfather", 30, "Paramount Pictures", 20000, "Francis Ford Coppola", 180, "English");
		FilmTorrent film_torrent_0 = FilmTorrent("The godfather", 10, "Paramount Pictures", 1000, "Francis Ford Coppola", 60, "English");
		SoftwareTorrent software_torrent = SoftwareTorrent("VMware Workstation", 20, "VMware", 1000, "VMware", "Linux", 2, 10, 3);


		GameTorrent game_torrent_2 = GameTorrent("CS:GO", 80, "Steam", 1200000, "Windows", 'M');
		FilmTorrent film_torrent_2 = FilmTorrent("Interstellar", 10, "PopCorn", 9000, "Christopher Nolan", 150, "English");
		SoftwareTorrent software_torrent_2 = SoftwareTorrent("VMware Workstation2", 30, "VMware", 100, "VMware", "Linux", 2, 0, 9);


		GameTorrent game_torrent_3 = GameTorrent("Resident Evil", 90, "Steam", 400000, "Windows", 'P');
		FilmTorrent film_torrent_3 = FilmTorrent("GoodFellas", 30, "Warner Bros", 20000, "Martin Scorsese", 120, "English");
		SoftwareTorrent software_torrent_3 = SoftwareTorrent("VMware Workstation3", 40, "VMware", 11000, "VMware", "Linux", 2, 0, 6);


		vector<GameTorrent*> g_torrents;
		vector<FilmTorrent*> f_torrents;
		vector<SoftwareTorrent*> s_torrents;


		g_torrents.push_back(&game_torrent);
		g_torrents.push_back(&game_torrent_2);
		g_torrents.push_back(&game_torrent_3);

		f_torrents.push_back(&film_torrent);
		f_torrents.push_back(&film_torrent_0);
		f_torrents.push_back(&film_torrent_2);
		f_torrents.push_back(&film_torrent_3);

		s_torrents.push_back(&software_torrent);
		s_torrents.push_back(&software_torrent_2);
		s_torrents.push_back(&software_torrent_3);

		vector<string> usernames;
		usernames.push_back("Peho");
		usernames.push_back("Dankata mangala");
		usernames.push_back("Khrum mishoka");

		server = Server(g_torrents, f_torrents, s_torrents, usernames);


		cout << "\nThis is returned torrents after calling findByTitle(CS:GO).\n" << endl;
		server.findByTitle("CS:GO");		
		cout << "\nThis is returned torrents after calling findGamesByMAturityRating(M).\n" << endl;
		for (int i = 0; i < server.findGamesByMAturityRating('M').size(); ++i){
			cout << server.findGamesByMAturityRating('M')[i]->toString() << endl;
		}
		cout << "\nThis is returned torrents after calling findFilmByDirector(Francis Ford Coppola).\n" << endl;
		for (int i = 0; i < server.findFilmByDirector("Francis Ford Coppola").size(); ++i){
			cout << server.findFilmByDirector("Francis Ford Coppola")[i]->toString() << endl;
		}
		cout << "\nThis is returned torrents after calling findSoftwareByVersion(2).\n" << endl;
		for (int  i = 0; i < server.findSoftwareByVersion(2).size(); ++i){
			cout << server.findSoftwareByVersion(2)[i]->toString() << endl;
		}

	}catch(const char * error){
		cout << error << endl;
	}
	// Ako pi6ete 6 vi kanq na po edna slatinska posta.
	return 0;
}