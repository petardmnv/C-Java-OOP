#ifndef TORRENT_H
#define TORRENT_H
#include <string>


class Torrent{
	string title;
	int size;
	string uploader;
	int downloads_count;
	virtual const string toString() = 0;
	virtual const string getClassType() = 0;
public:
	Torrent(){}
	Torrent(string title, int size, string uploader,
		int downloads_count){}
	Torrent(const Torrent& t){}

	string getTitle() const {}
	int getSize() const {}
	string getUploader() const {}
	int getDownloadsCount() const {}

};

#endif