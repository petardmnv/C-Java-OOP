#include "filmtorrent.h"
using namespace std;

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

