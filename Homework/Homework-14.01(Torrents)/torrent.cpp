#include <iostream>
#include <string>

using namespace std;

class Torrent{
	string title;
	int size;
	string uploader;
	int downloads_count;
public:
	Torrent(string title, int size, string uploader,
		int downloads_count){
		this->title = title;
		this->size = size;
		this->uploader = uploader;
		this->downloads_count = downloads_count;
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
	GameTorrent(string title, int size, string uploader,
		int downloads_count, char maturity_rating) : Torrent(title, size, uploader, downloads_count){
		if (maturity_rating != 'E' && maturity_rating != 'M', maturity_rating != 'P'){
			throw "Invallid maturity_rating value";
		}
		this->maturity_rating = maturity_rating;
	}
	char getMaturityRating() const { return this->maturity_rating; }
};


class FilmTorrent : public Torrent{
	string director;
	int duration;
	string language;
public:
	FilmTorrent(string title, int size, string uploader,
		int downloads_count, string director, int duration, string language) : Torrent(title, size, uploader, downloads_count){
		this->director = director;
		this->duration = duration;
		this->language = language;
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
	SoftwareTorrent(string title, int size, string uploader,
		int downloads_count, string producer, string system, 
		int major, int minor, int patch) : Torrent(title, size, uploader, downloads_count){
		this->major = major;
		this->minor = minor;
		this->patch = patch;
	}
	string getProducer() const { return this->producer; }
	string getSystem() const { return this->system; }
	int getMajor() const { return this->major; }
	int getMinor() const { return this->minor; }
	int getPatch() const { return this->patch; }
	
};

int main(int argc, char const *argv[]){

	return 0;
}