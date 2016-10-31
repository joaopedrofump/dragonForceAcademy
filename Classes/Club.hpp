#pragma once

#include "Season.hpp"
//#include "Goalkeeper.hpp"

//class Season;
//class Level;

#define MAINFOLDER_LEO "C:\\Users\\Leo\\Desktop\\FEUP\\2º ANO\\AEDA\\DragonForceAcademy\\DragonForceAcademy\\Pastas GitHub\\TextFiles"




class Club {
	string name;
	vector<Worker*> allWokers;
	vector<Season*> seasons;
	unsigned int numberOfSeasons;

	string fileName;


public:
	Club(string name, vector<Season*> seasonsVector);
	Club(string fileClub);

	string getName() const;
	vector<Worker*> getWorkers() const;
	vector<Season*> getSeasons() const;



};