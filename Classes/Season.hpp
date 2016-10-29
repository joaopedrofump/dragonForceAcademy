#pragma once

#include "Level.h"

class Season {
	unsigned int year;

	vector<Level*> levels;
	
	string fileName;

public:
	Season(unsigned int year, vector<Level*> levelsVector);
	Season(ifstream &in, string fileClub);

	unsigned int getYear() const;

};