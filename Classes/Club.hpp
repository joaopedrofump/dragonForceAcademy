#pragma once

#include "Utils.hpp"
#include "Season.hpp"

#define MAINFOLDER "C:\\Users\\Leo\\Desktop\\FEUP\\2º ANO\\AEDA\\DragonForceAcademy\\DragonForceAcademy\\Pastas GitHub"


class Club {
	string name;
	vector<Season*> seasons;
	unsigned int numberOfSeasons;
	string fileClub;

public:
	Club(string name, vector<Season*> seasonsVector);
	Club(string fileClub);

	string getName() const;
	vector<Season*> getSeasons() const;
};