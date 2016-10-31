#include "Season.hpp"

//#include "Club.hpp"

Season::Season(ifstream &in, string fileClub) {

	string tmpString;
	getline(in, tmpString);

	ifstream inStreamSeason;

	inStreamSeason.open((fileClub + "\\" + tmpString).c_str());

	while (!inStreamSeason.eof()) {

		Level* actualLevel = new Level(inStreamSeason, tmpString, fileClub);

		this->levels.push_back(actualLevel);
	}

	inStreamSeason.close();
}