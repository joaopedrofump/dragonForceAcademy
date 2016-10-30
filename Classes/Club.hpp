#pragma once

//#include "Season.hpp"
#include "Goalkeeper.hpp"

class Season;
class Level;

#define MAINFOLDER_LEO "C:\\Users\\Leo\\Desktop\\FEUP\\2º ANO\\AEDA\\DragonForceAcademy\\DragonForceAcademy\\Pastas GitHub\\TextFiles"

extern const map<string, CoachType> coachTypeMap;

extern const map<string, Position> positionsMap;

extern const map<string, DefenderPosition> defendersMap;

extern const map<string, MidfielderPosition> midfieldersMap;

extern const map<string, ForwardPosition> forwardsMap;


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