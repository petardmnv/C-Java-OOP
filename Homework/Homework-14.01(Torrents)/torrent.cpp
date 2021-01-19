#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Torrent{
	string title;
	int size;
	string uploader;
	int downloads_count;
	virtual const string toString();
public:
	//Torrent(){}
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
	/*Torrent(const Torrent& t){
		this->title = t.getTitle();
		this->size = t.getSize();
		this->uploader = t.getUploader();
		this->downloads_count = t.getDownloadsCount();
	}*/

	string getTitle() const { return this->title; }
	int getSize() const { return this->size; }
	string getUploader() const { return this->uploader; }
	int getDownloadsCount() const { return this->downloads_count; }

};


class GameTorrent : public Torrent{
	string system;
	char maturity_rating;

public:
	//GameTorrent(){}
	GameTorrent(string title, int size, string uploader,
		int downloads_count, string system, char maturity_rating) : Torrent(title, size, uploader, downloads_count){
		if (maturity_rating != 'E' && maturity_rating != 'M', maturity_rating != 'P'){
			throw "Invallid maturity_rating value";
		}
		if (system.size() == 0){
			throw "This system name is invalid.";
		}
		this->maturity_rating = maturity_rating;
		this->system = system;
	}
	/*GameTorrent(const GameTorrent& t){
		this->maturity_rating = t.getMaturityRating();
		this->system = t.getSystem();
	}*/

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
	//FilmTorrent(){}
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
	/*FilmTorrent(const FilmTorrent& t){
		this->director = t.getDirector();
		this->duration = t.getDuration();
		this->language = t.getLanguage();		
	}*/

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
	//SoftwareTorrent(){}
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
	/*SoftwareTorrent(const SoftwareTorrent& t){
		this->producer = t.getProducer();
		this->system = t.getSystem();
		this->major = t.getMajor();
		this->minor = t.getMinor();
		this->patch = t.getPatch();
	}*/

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


/*class Server{

public:

};*/
int main(int argc, char const *argv[]){
	try{
		GameTorrent game_torrent = GameTorrent("Rust", 120, "Steam", 12000, "Windows", 'M');
		FilmTorrent film_torrent = FilmTorrent("The godfather", 30, "Warrnet", 20000, "Francis Ford Coppola", 180, "English");
		SoftwareTorrent software_torrent = SoftwareTorrent("VMware Workstation", 20, "VMware", 1000, "VMware", "Linux", 2, 10, 3);

		/*cout << game_torrent.toString() << endl;
		cout << film_torrent.toString() << endl;
		cout << software_torrent.toString() << endl;*/
	}catch(const char * error){
		cout << error << endl;
	}
	return 0;
}