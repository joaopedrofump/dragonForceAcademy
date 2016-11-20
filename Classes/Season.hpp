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

	//! Season constructors

	/*!
	*	This is a constructor that creates a new season using the season's year and a vector that includes all the levels of the season
	*/
	Season(unsigned int year, vector<Level*> levelsVector);

	/*!
	*	This is a constructor that creates a new season using the season's name and the parent club
	*/
	Season(string seasonName, Club* parentClub);
	unsigned int getYear() const;
	vector<Level*> getLevels() const;
	string getPathToSeasonFolder() const;
	string getSeasonName() const;
	Date getInitialDate() const;
	Date getEndDate() const;
};


