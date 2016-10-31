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
	Season(string seasonName, string fileClub, Club* club);

	unsigned int getYear() const;
};
