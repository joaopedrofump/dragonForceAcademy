#pragma once

#include "Season.hpp"
//#include "Goalkeeper.hpp"

//class Season;
//class Level;

extern const map<string, CoachType> coachTypeMap;

class Club {
	string name;
	map<unsigned int, Worker*> allWorkers;
	vector<Season*> seasons;
	unsigned int numberOfSeasons;

	string fileName;


public:
	Club(string name, vector<Season*> seasonsVector);
	Club(string fileClub);

	string getName() const;
	map<unsigned int, Worker*> getWorkers() const;
	vector<Season*> getSeasons() const;

	map<unsigned int, Worker*> getAthletes() const;
	map<unsigned int, Worker*> getCoaches() const;

	void showAthletes(bool onlyActives = false) const;




};
