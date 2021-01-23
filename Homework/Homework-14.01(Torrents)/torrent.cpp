#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Torrent{
	string title;
	int size;
	string uploader;
	int downloads_count;
public:
	virtual const string toString() = 0;
	virtual const string getClassType() = 0;
	Torrent(){}
	Torrent(string title, int size, string uploader,
		int downloads_count){
		if (size <= 0){
			throw "This size is invalid.";
		}
		if (downloads_count < 0){
			throw "This downloads_count is invalid.";
		}
		if (title.size() == 0){
			throw "This title is invalid.";
		}
		if (uploader.size() == 0){
			throw "This uploader name is invalid.";
		}
		this->title = title;
		this->size = size;
		this->uploader = uploader;
		this->downloads_count = downloads_count;
	}
	Torrent(const Torrent& t){
		this->title = t.getTitle();
		this->size = t.getSize();
		this->uploader = t.getUploader();
		this->downloads_count = t.getDownloadsCount();
	}

	string getTitle() const { return this->title; }
	int getSize() const { return this->size; }
	string getUploader() const { return this->uploader; }
	int getDownloadsCount() const { return this->downloads_count; }

};


class GameTorrent : public Torrent{
	string system;
	char maturity_rating;

public:
	GameTorrent(){}
	GameTorrent(string title, int size, string uploader,
		int downloads_count, string system, char maturity_rating) : Torrent(title, size, uploader, downloads_count){
		if (maturity_rating != 'E' && maturity_rating != 'M' && maturity_rating != 'P'){
			throw "Invallid maturity_rating value";
		}
		if (system.size() == 0){
			throw "This system name is invalid.";
		}
		this->maturity_rating = maturity_rating;
		this->system = system;
	}
	GameTorrent(const GameTorrent& t){
		this->maturity_rating = t.getMaturityRating();
		this->system = t.getSystem();
	}

	const string getClassType(){
		return "GameTorrent";
	}

	const string toString(){
		ostringstream buffer;
		buffer << "Game torrent info:\nTitle: " << getTitle() << "\nSize: " << getSize()
		<< "\nUploaded by: " << getUploader() << "\nDownloads count: " << getDownloadsCount()
		<< "\nFor system: " << system << "\nMaturity rating: " << maturity_rating << endl;
		return buffer.str();
	}

	char getMaturityRating() const { return this->maturity_rating; }
	string getSystem() const { return this->system; }
};


class FilmTorrent : public Torrent{
	string director;
	int duration;
	string language;
public:
	FilmTorrent(){}
	FilmTorrent(string title, int size, string uploader,
		int downloads_count, string director, int duration, string language) : Torrent(title, size, uploader, downloads_count){
		if (director.size() == 0){
			throw "This director name is invalid.";
		}
		if (duration <= 0){
			throw "This duration is invalid.";
		}
		if (language.size() == 0){
			throw "This language is invalid.";
		}
		this->director = director;
		this->duration = duration;
		this->language = language;
	}
	FilmTorrent(const FilmTorrent& t){
		this->director = t.getDirector();
		this->duration = t.getDuration();
		this->language = t.getLanguage();		
	}

	const string getClassType(){
		return "FilmTorrent";
	}

	const string toString(){
		ostringstream buffer;
		buffer << "Film torrent info:\nTitle: " << getTitle() << "\nSize: " << getSize()
		<< "\nUploaded by: " << getUploader() << "\nDownloads count: " << getDownloadsCount()
		<< "\nFilm director: " << director << "\nFilm duration: " << duration
		<< "\nFilm language: " << language << endl;
		return buffer.str();
	}	

	string getDirector() const { return this->director; }
	int getDuration() const { return this->duration; }
	string getLanguage() const { return this->language; }
};


class SoftwareTorrent : public Torrent{
	string producer;
	string system;
	int major;
	int minor;
	int patch;
public:
	SoftwareTorrent(){}
	SoftwareTorrent(string title, int size, string uploader,
		int downloads_count, string producer, string system, 
		int major, int minor, int patch) : Torrent(title, size, uploader, downloads_count){
		if (producer.size() == 0){
			throw "This producer name is invalid.";
		}
		if (system.size() == 0){
			throw "This system is invalid.";
		}
		if (major < 0){
			throw "This major is invalid.";
		}
		if (minor < 0){
			throw "This minor is invalid.";
		}
		if (patch < 0){
			throw "This patch is invalid.";
		}
		this->producer = producer;
		this->system = system;
		this->major = major;
		this->minor = minor;
		this->patch = patch;
	}
	SoftwareTorrent(const SoftwareTorrent& t){
		this->producer = t.getProducer();
		this->system = t.getSystem();
		this->major = t.getMajor();
		this->minor = t.getMinor();
		this->patch = t.getPatch();
	}

	const string getClassType(){
		return "SoftwareTorrent";
	}

	const string toString(){
		ostringstream buffer;
		buffer << "Software torrent info:\nTitle: " << getTitle() << "\nSize: " << getSize()
		<< "\nUploaded by: " << getUploader() << "\nDownloads count: " << getDownloadsCount()
		<< "\nSftware producer: " << producer << "\nSoftware system: " << system
		<< "\nSoftware version: " << major << ":" << minor << ":" << patch << endl;
		return buffer.str();
	}	

	string getProducer() const { return this->producer; }
	string getSystem() const { return this->system; }
	int getMajor() const { return this->major; }
	int getMinor() const { return this->minor; }
	int getPatch() const { return this->patch; }
	
};


class Server{
	vector<Torrent*> torrents;
	vector<string> usernames;
public:
	Server(){}
	Server(vector<Torrent*> torrents, vector<string> usernames) : torrents(torrents), usernames(usernames){
		// Lmao that is working somehow
		if (torrents.size() == 0){
			throw "Empty game torrents vector.";
		}
		if (usernames.size() == 0){
			throw "Empty username vector.";
		}
	} 

	vector<Torrent*> findByTitle(string title){
		vector<Torrent*> found_torrents;
		for (int i = 0; i < this->torrents.size(); ++i){
			if (title == torrents[i]->getTitle()){
				found_torrents.push_back(torrents[i]);
			}
		}
		if (!found_torrents.size()){
			throw "Didn't found torrents with this title";
		}
		return found_torrents;
	}

	vector<Torrent*> findGamesByMAturityRating(char maturity_rating){
		vector<Torrent*> found_game_torrents;
		for (int i = 0; i < this->torrents.size(); ++i){
			if (torrents[i]->getClassType() == "GameTorrent"){
				if (maturity_rating == torrents[i]->getMaturityRating()){
					found_game_torrents.push_back(torrents[i]);
				}
			}
		}
		if (!found_game_torrents.size()){
			throw "Didn't found game torrents with this maturity rating";
		}
		return found_game_torrents;
	}

	vector<Torrent*> findFilmByDirector(string director_name){
		vector<Torrent*> found_film_torrents;
		for (int i = 0; i < this->torrents.size(); ++i){
			if (torrents[i]->getClassType() == "FilmTorrent"){
				if (director_name == torrents[i]->getDirector()){
					found_film_torrents.push_back(torrents[i]);
				}
			}
		}
		if (!found_film_torrents.size()){
			throw "Didn't found film torrents with this director name";
		}
		return found_film_torrents;
	}

	vector<Torrent*> findSoftwareByVersion(int major){
		vector<Torrent*> found_software_torrents;
		for (int i = 0; i < this->torrents.size(); ++i){
			if (torrents[i]->getClassType() == "SoftwareTorrent"){
				if (major == torrents[i]->getMajor()){
					found_software_torrents.push_back(torrents[i]);
				}
			}
		}
		if (!found_software_torrents.size()){
			throw "Didn't found software torrents with this major";
		}
		return found_software_torrents;
	}

};
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


		cout << game_torrent.toString() << endl;

		vector<Torrent*> torrents;


		torrents.push_back(&game_torrent);
		torrents.push_back(&game_torrent_2);
		torrents.push_back(&game_torrent_3);

		torrents.push_back(&film_torrent);
		torrents.push_back(&film_torrent_0);
		torrents.push_back(&film_torrent_2);
		torrents.push_back(&film_torrent_3);

		torrents.push_back(&software_torrent);
		torrents.push_back(&software_torrent_2);
		torrents.push_back(&software_torrent_3);

		vector<string> usernames;
		usernames.push_back("Peho");
		usernames.push_back("Dankata mangala");
		usernames.push_back("Khrum mishoka");

		server = Server(torrents, usernames);

		for (int i = 0; i < server.findByTitle("CS:GO").size(); ++i){
			cout << server.findByTitle("CS:GO")[i]->toString() << endl;
		}
		for (int i = 0; i < server.findGamesByMAturityRating('M').size(); ++i){
			cout << server.findGamesByMAturityRating('M')[i]->toString() << endl;
		}
		for (int i = 0; i < server.findFilmByDirector("Christopher Nolan").size(); ++i){
			cout << server.findFilmByDirector("Christopher Nolan")[i]->toString() << endl;
		}
		for (int  i = 0; i < server.findSoftwareByVersion(2).size(); ++i){
			cout << server.findSoftwareByVersion(2)[i]->toString() << endl;
		}

	}catch(const char * error){
		cout << error << endl;
	}
	return 0;
}