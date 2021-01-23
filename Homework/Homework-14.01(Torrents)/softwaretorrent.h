#ifndef SOFTWARETORRENT_H
#define SOFTWARETORRENT_H
#include <string>
#include <ostream>
#include <sstream>
#include <iostream>
#include "torrent.h"
using namespace std;

class SoftwareTorrent : public Torrent{
	string producer;
	string system;
	int major;
	int minor;
	int patch;
public:
	SoftwareTorrent();
	SoftwareTorrent(string title, int size, string uploader,
		int downloads_count, string producer, string system, 
		int major, int minor, int patch) : Torrent(title, size, uploader, downloads_count), producer(producer), system(system), major(major), minor(minor), patch(patch){
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
	}
	SoftwareTorrent(const SoftwareTorrent& t){
		this->producer = t.getProducer();
		this->system = t.getSystem();
		this->major = t.getMajor();
		this->minor = t.getMinor();
		this->patch = t.getPatch();
	}

	const string getClassType();
	const string toString();

	string getProducer() const { return this->producer; }
	string getSystem() const { return this->system; }
	int getMajor() const { return this->major; }
	int getMinor() const { return this->minor; }
	int getPatch() const { return this->patch; }
	
};

#endif