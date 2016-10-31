#pragma once

#include "Level.h"

//#include "Goalkeeper.hpp"


class Club;
class Season {
	unsigned int year;

	vector<Level*> levels;
	
	string fileName;

public:
	Season(unsigned int year, vector<Level*> levelsVector);
	Season(ifstream &in, string fileClub, Club* club);

	unsigned int getYear() const;
	vector<Level*> getLevels() const;
};