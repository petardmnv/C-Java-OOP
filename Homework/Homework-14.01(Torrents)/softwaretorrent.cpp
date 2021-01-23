#include "softwaretorrent.h"

	SoftwareTorrent::SoftwareTorrent(string title, int size, string uploader,
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
	SoftwareTorrent::SoftwareTorrent(const SoftwareTorrent& t){
		this->producer = t.getProducer();
		this->system = t.getSystem();
		this->major = t.getMajor();
		this->minor = t.getMinor();
		this->patch = t.getPatch();
	}

	const string SoftwareTorrent::getClassType(){
		return "SoftwareTorrent";
	}

	const string SoftwareTorrent::toString(){
		ostringstream buffer;
		buffer << "Software torrent info:\nTitle: " << getTitle() << "\nSize: " << getSize()
		<< "\nUploaded by: " << getUploader() << "\nDownloads count: " << getDownloadsCount()
		<< "\nSftware producer: " << producer << "\nSoftware system: " << system
		<< "\nSoftware version: " << major << ":" << minor << ":" << patch << endl;
		return buffer.str();
	}	

	string SoftwareTorrent::getProducer() const { return this->producer; }
	string SoftwareTorrent::getSystem() const { return this->system; }
	int SoftwareTorrent::getMajor() const { return this->major; }
	int SoftwareTorrent::getMinor() const { return this->minor; }
	int SoftwareTorrent::getPatch() const { return this->patch; }
