#pragma once

#include "Utils.hpp"
#include "Level.h"

class Season {
	unsigned int year;
	vector<Level*> levels;
public:
	Season(unsigned int year, vector<Level*> levelsVector);
	Season(ifstream &in);

	unsigned int getYear() const;

};