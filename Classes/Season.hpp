#pragma once

#include "Level.h"

class Club;
class Season {
	unsigned int year;
    Date initialDate;
    Date endDate;
	vector<Level*> levels;
	string pathToSeasonFolder;
    string seasonName;
    void setDateInterval();

public:
	Season(unsigned int year, vector<Level*> levelsVector);
	Season(string seasonName, Club* parentClub);
    unsigned int getYear() const;
	vector<Level*> getLevels() const;
    string getPathToSeasonFolder() const;
    string getSeasonName() const;
    Date getInitialDate() const;
    Date getEndDate() const;
};


