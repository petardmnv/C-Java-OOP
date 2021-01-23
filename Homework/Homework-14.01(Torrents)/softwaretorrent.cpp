#include "softwaretorrent.h"
using namespace std;

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
