#include "gametorrent.h"

	GameTorrent::GameTorrent(string title, int size, string uploader,
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
	GameTorrent::GameTorrent(const GameTorrent& t){
		this->maturity_rating = t.getMaturityRating();
		this->system = t.getSystem();
	}

	const string GameTorrent::getClassType(){
		return "GameTorrent";
	}

	const string GameTorrent::toString(){
		ostringstream buffer;
		buffer << "Game torrent info:\nTitle: " << getTitle() << "\nSize: " << getSize()
		<< "\nUploaded by: " << getUploader() << "\nDownloads count: " << getDownloadsCount()
		<< "\nFor system: " << system << "\nMaturity rating: " << maturity_rating << endl;
		return buffer.str();
	}

	char GameTorrent::getMaturityRating() const { return this->maturity_rating; }
	string GameTorrent::getSystem() const { return this->system; }