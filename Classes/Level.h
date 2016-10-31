#pragma once

#include "Goalkeeper.hpp"

using namespace std;

extern const map<string, CoachType> coachTypeMap;

extern const map<string, Position> positionsMap;

extern const map<string, DefenderPosition> defendersMap;

extern const map<string, MidfielderPosition> midfieldersMap;

extern const map<string, ForwardPosition> forwardsMap;


//class Club;
class Level
{
private:
	
	ageLevel ageLevelName;

	vector<unsigned int> trainersIds;
	map<unsigned int, Info*> mapInfoSeason;

	unsigned int mainCoachID;

	unsigned int minAge;
	unsigned int maxAge;

	unsigned int minHeight;

	//vector<Tournament> tournaments;
	//vector<Training> trainings;
	//vector<Match> friendlys;

public:

	//Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<Athlete*, Info*> mapInfoSeason);
	Level(string yearOfSeason, string fileClub, string levelName);





};
