#pragma once

#include "Goalkeeper.hpp"

class Club;

class Level {
private:
	
	ageLevel levelEnum;
    string levelName;
    string pathToLevelFolder;
    string pathToLevelAthletesFile;
    string pathToLevelCoachesFile;

    int levelMainCoach;
	vector<unsigned int> coachesIdsVector;
	map<unsigned int, Info*> mapInfoPlayers;

	unsigned int minAge;
	unsigned int maxAge;

	char minHeight;

	//vector<Tournament> tournaments;
	//vector<Training> trainings;
	//vector<Match> friendlys;

public:

	//Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<Athlete*, Info*> mapInfoSeason);
	Level(string yearOfSeason, string pathToSeasonFolder, string levelName, Club* parentClub);
	unsigned int getMinAge() const;
	unsigned int getMaxAge() const;
	char getMinHeight() const;
    map<unsigned int, Info*> getMapInfoPlayers() const;
    vector<unsigned int> getCoaches() const;
    Level* addAthleteToLevel(pair<unsigned int, Info*> playerInfo);
    string getLevelName() const;
    int getMainCoachId() const;
    
    string getPathToLevelFolder() const;
    string getPathToLevelAthletesFile() const;
    string getPathToLevelCoachesFile() const;




};
