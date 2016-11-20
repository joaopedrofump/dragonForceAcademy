#pragma once

#include "Goalkeeper.hpp"
#include "Match.hpp"
#include "Training.hpp"
#include "Tournament.hpp"

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
    string pathToLevelTrainingsFile;
    string pathToLevelTournamentsFile;
    string pathToLevelTournamentsFolder;
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
	vector<Tournament*> tournaments;

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
    vector<Tournament*> getTournaments() const;
    
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

    
    void sortTrainings();
    
    void saveLevelTrainings() const;
    
    void saveLevelTournaments() const;
    
    void scheduleTraining(Date trainingDate);
    
    //registar treino já agendado
    void registerTraining(unsigned int trainingId, vector<unsigned int> missingPlayers);
    
    //registar treino não agendado
    void registerTraining(Date trainingDate, vector<unsigned int> missingPlayers);
    
    
    //! Get the all the trainings of the level.
    /*!
     \param criteria criteria enum argument: id = sorted by id, date = sorted by date, numberOfPlayers = sorted by number of players who trained
     \param order order enum argument: ascending = sorted ascending, descending = sorted descending
     \param listType char argument: a = all trainings, p = past trainings, r = registed trainings, n = trainings not registered, f = future trainings
     \return Returns a vector of string vectors where each string vector contains the list of trainings attributes
     */
    
    vector<vector<string>> getTrainingsList(SortCriteria criteria, SortOrder order, char listType = 'a') const;
    
    void addTournament(Date initialDate, Date endDate, vector<string> tournamentClubs, string name);
    
    vector<vector<string>> getTournamentMatches(unsigned int tournamentId) const;
    
    vector<unsigned int> filterPlayers(vector<unsigned int> originalPlayerIdsVector) const;
    
    Club* getParentClub() const;
    
};
