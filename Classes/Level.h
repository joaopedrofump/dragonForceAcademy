#pragma once

#include "Goalkeeper.hpp"
#include "Match.hpp"
#include "Training.hpp"

class Club;
class Training;

class Level {
private:
	Club* parentClub;
	ageLevel levelEnum;
    string levelName;
    string pathToLevelFolder;
    string pathToLevelAthletesFile;
    string pathToLevelCoachesFile;
    string pathToLevelMatchesFile;
    string pathToLevelMatchesFolder;
    string yearOfSeason;

    unsigned int lastMatchId;
    vector<Match*> levelMatches;
    vector<Training*> levelTrainings;

    int levelMainCoach;
	vector<unsigned int> coachesIdsVector;
	map<unsigned int, Info*> mapInfoPlayers;

	unsigned int minAge;
	unsigned int maxAge;

	char minHeight;

	//vector<Tournament> tournaments;

public:

	//Level(ageLevel ageLevelName, vector<Coach*> coachesVector, map<Athlete*, Info*> mapInfoSeason);
	Level(string yearOfSeason, string pathToSeasonFolder, string levelName, Club* parentClub);
	unsigned int getMinAge() const;
	unsigned int getMaxAge() const;
	char getMinHeight() const;
    map<unsigned int, Info*> getMapInfoPlayers() const;
    vector<unsigned int> getCoaches() const;
    Level* addAthleteToLevel(pair<unsigned int, Info*> playerInfo);
	Level* addCoachToLevel(unsigned int idCoach, bool mainCoach = false);
    
    string getLevelName() const;
    int getMainCoachId() const;
	string getYear() const;
    
    string getPathToLevelFolder() const;
    string getPathToLevelAthletesFile() const;
    string getPathToLevelCoachesFile() const;
    string getPathToLevelMatchesFile() const;
    string getPathToLevelMatchesFolder() const;
    
    unsigned int getLastMatchId() const;
    void updateLastMatchId();
    
    vector<Match*> getAllLevelMatches(bool onlyNotPlayed = false) const;
	vector<Match*> getMatchesReadyToPlay() const;

	Table showAthletesOfLevel() const;
    vector<Training*> getAllLevelTrainings() const;
    Level* addMatchToLevel(Match* newMatch);
    Level* addTrainingToLevel(Training* newTraining);

	void showMatches(vector<Match*> matches);

};
