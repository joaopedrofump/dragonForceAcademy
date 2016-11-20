#pragma once

#include "Level.h"

class Club;
class Season {
	unsigned int year; //! season's year
	vector<Level*> levels; //! vector including all the levels of the season
	string pathToSeasonFolder; //! path to the season folder
    string seasonName; //! season's name

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
	
	/*!
	*	This is a method that gets the season's year
	*/
	unsigned int getYear() const;
	
	/*!
	*	This is a method that gets the vector that includes all the levels of the respective season
	*/
	vector<Level*> getLevels() const;
    
	/*!
	*	This is a method that gets the path to the season folder
	*/
	string getPathToSeasonFolder() const;
    
	/*!
	*	This is a method that gets the season's name
	*/
	string getSeasonName() const;
};


