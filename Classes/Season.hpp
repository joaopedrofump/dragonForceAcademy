#pragma once

#include "Level.h"

class Club;
class Season {
	unsigned int year;
	vector<Level*> levels;
	string fileName;

public:
	Season(unsigned int year, vector<Level*> levelsVector);
	Season(string seasonName, string fileClub, Club* parentClub);
    string getFileName() const;
	unsigned int getYear() const;

	vector<Level*> getLevels() const;
};

