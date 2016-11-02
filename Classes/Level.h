#pragma once

#include "Goalkeeper.hpp"

class Club;

class Level {
private:
	
	ageLevel ageLevelName;

	vector<unsigned int> trainersIds;
	map<unsigned int, Info*> mapInfoPlayers;

	unsigned int mainCoachID;

	unsigned int minAge;
	unsigned int maxAge;

	char minHeight;

	//vector<Tournament> tournaments;
	//vector<Training> trainings;
	//vector<Match> friendlys;

public:

	//Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<Athlete*, Info*> mapInfoSeason);
	Level(string yearOfSeason, string fileClub, string levelName, Club* parentClub);
	unsigned int getMinAge() const;
	unsigned int getMaxAge() const;
	char getMinHeight() const;
    map<unsigned int, Info*> getMapInfoPlayers() const;
    Level* addAthleteToLevel(pair<unsigned int, Info*> playerInfo);
    string levelName() const;


};
