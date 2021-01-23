#include "gametorrent.h"
using namespace std;

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