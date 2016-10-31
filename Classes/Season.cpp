#include "Season.hpp"

//#include "Club.hpp"


Season::Season(unsigned int year, vector<Level*> levelsVector){
	this->year = year;
	this->levels = levelsVector;
}

Season::Season(string seasonName, string fileClub) {

	ifstream inStreamSeason;

	inStreamSeason.open((fileClub + stringPath("/") + seasonName).c_str());

	while (!inStreamSeason.eof()) {


		Level* actualLevel = new Level(inStreamSeason, seasonName, fileClub);


		this->levels.push_back(actualLevel);
	}

	inStreamSeason.close();
}

unsigned int Season::getYear() const
{
	return year;
}

vector<Level*> Season::getLevels() const
{
	return levels;
}
