#include "Season.hpp"

//#include "Club.hpp"


Season::Season(unsigned int year, vector<Level*> levelsVector){
	this->year = year;
	this->levels = levelsVector;
}

Season::Season(string seasonName, string fileClub) {
    
    this->year = stoi(seasonName);
    this->fileName = stringPath(fileClub + "/" + seasonName);
    
    Level* levelu13 = new Level(seasonName, fileName, "U13");
    Level* levelu15 = new Level(seasonName, fileName, "U15");
    Level* levelu17 = new Level(seasonName, fileName, "U17");
    Level* levelu19 = new Level(seasonName, fileName, "U19");
    Level* seniors = new Level(seasonName, fileName, "Seniors");
    
    this->levels.push_back(levelu13);
    this->levels.push_back(levelu15);
    this->levels.push_back(levelu17);
    this->levels.push_back(levelu19);
    this->levels.push_back(seniors);
    
}
unsigned int Season::getYear() const
{
	return year;
}

vector<Level*> Season::getLevels() const
{
	return levels;
}

string Season::getFileName() const {
    
    return this->fileName;
    
}
