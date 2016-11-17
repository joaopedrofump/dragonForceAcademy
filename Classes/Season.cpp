#include "Season.hpp"
#include "Club.hpp"

Season::Season(unsigned int year, vector<Level*> levelsVector){
	this->year = year;
	this->levels = levelsVector;
}

Season::Season(string seasonName, Club* parentClub) {
    
    this->year = stoi(seasonName);
    this->seasonName = seasonName;
    this->pathToSeasonFolder = stringPath(parentClub->getPathToClubFolder() + "/" + this->seasonName);
    
    Level* levelu13 = new Level(this->seasonName, this->pathToSeasonFolder, "U13", parentClub);
    Level* levelu15 = new Level(this->seasonName, this->pathToSeasonFolder, "U15", parentClub);
    Level* levelu17 = new Level(this->seasonName, this->pathToSeasonFolder, "U17", parentClub);
    Level* levelu19 = new Level(this->seasonName, this->pathToSeasonFolder, "U19", parentClub);
    Level* seniors = new Level(this->seasonName, this->pathToSeasonFolder, "Seniors", parentClub);
    
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

string Season::getPathToSeasonFolder() const {
    return this->pathToSeasonFolder;
}

string Season::getSeasonName() const {
    return this->seasonName;
}

