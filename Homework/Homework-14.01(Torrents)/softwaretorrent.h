#ifndef SOFTWARETORRENT_H
#define SOFTWARETORRENT_H
#include <string>
#include <torrent.h>

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
		int major, int minor, int patch) : Torrent(title, size, uploader, downloads_count){}
	SoftwareTorrent(const SoftwareTorrent& t){}

	const string getClassType(){}

	const string toString(){}	

	string getProducer() const {}
	string getSystem() const {}
	int getMajor() const {}
	int getMinor() const {}
	int getPatch() const {}
	
};

#endif