#include "Club.hpp"

Club::Club(string name, vector<Season*> seasonsVector) : name(name), seasons(seasonsVector) {}

Club::Club(string fileClub) {

	this->fileName = fileClub;

	ifstream inStreamClub;

	inStreamClub.open(this->fileName.c_str());
	if (!inStreamClub.eof()) {
		getline(inStreamClub, this->name);
	}

	//   READ INFORMATIONS FROM FILESEASONS

	while (!inStreamClub.eof()) {
		
		Season* actualSeason = new Season(inStreamClub);

		this->seasons.push_back(actualSeason);
	}


}

string Club::getName() const {
	return name;
}

vector<Season*> Club::getSeasons() const {
	return seasons;
}


