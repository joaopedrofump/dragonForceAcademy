#pragma once

#include "Season.hpp"

#define MAINFOLDER_LEO "C:\\Users\\Leo\\Desktop\\FEUP\\2º ANO\\AEDA\\DragonForceAcademy\\DragonForceAcademy\\Pastas GitHub\\TextFiles"


class Club {
	string name;
	vector<Season*> seasons;
	unsigned int numberOfSeasons;

	string fileName;


public:
	Club(string name, vector<Season*> seasonsVector);
	Club(string fileClub);

	string getName() const;
	vector<Season*> getSeasons() const;
};