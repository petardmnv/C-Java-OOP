#ifndef TORRENT_H
#define TORRENT_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>
using namespace std;


class Torrent{
	string title;
	int size;
	string uploader;
	int downloads_count;
	virtual const string toString() = 0;
	virtual const string getClassType() = 0;
public:
	Torrent();
	Torrent(string title, int size, string uploader,
		int downloads_count) : title(title), size(size), uploader(uploader), downloads_count(downloads_count){
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
	}
	Torrent(const Torrent& t):title(t.getTitle()), size(t.getSize()), uploader(t.getUploader()), downloads_count(t.getDownloadsCount()){}

	string getTitle() const { return this->title; }
	int getSize() const { return this->size; }
	string getUploader() const { return this->uploader; }
	int getDownloadsCount() const { return this->downloads_count; }

};

#endif