#include "filmtorrent.h"

	FilmTorrent::FilmTorrent(string title, int size, string uploader,
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
	FilmTorrent::FilmTorrent(const FilmTorrent& t){
		this->director = t.getDirector();
		this->duration = t.getDuration();
		this->language = t.getLanguage();		
	}

	const string FilmTorrent::getClassType(){
		return "FilmTorrent";
	}

	const string FilmTorrent::toString(){
		ostringstream buffer;
		buffer << "Film torrent info:\nTitle: " << getTitle() << "\nSize: " << getSize()
		<< "\nUploaded by: " << getUploader() << "\nDownloads count: " << getDownloadsCount()
		<< "\nFilm director: " << director << "\nFilm duration: " << duration
		<< "\nFilm language: " << language << endl;
		return buffer.str();
	}	

	string FilmTorrent::getDirector() const { return this->director; }
	int FilmTorrent::getDuration() const { return this->duration; }
	string FilmTorrent::getLanguage() const { return this->language; }