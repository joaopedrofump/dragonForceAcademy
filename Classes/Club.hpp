#pragma once

#include "Goalkeeper.hpp"

class Season;
class Match;
class Level;

extern const map<string, CoachType> coachTypeMap;

class Club {
	string clubName;
    bool programClub;
	map<unsigned int, Worker*> allWorkers;
	vector<Season*> seasons;
	unsigned int numberOfSeasons;
    string pathToClubFolder;
    string pathToClubAthletesFile;
    string pathToClubCoachesFile;
    string pathToClubInfoFile;

public:
	Club(string clubName, bool empty = false);
	string getName() const;
	map<unsigned int, Worker*> getWorkers() const;
	vector<Season*> getSeasons() const;

	void addPlayer(Position pos, string name, Date birthdate, unsigned int civilID, unsigned char height);
	bool removeAthlete(unsigned int athleteId);

	map<unsigned int, Worker*> getAthletes(bool onlyActives = false) const;
	map<unsigned int, Worker*> getInactives() const;
	map<unsigned int, Worker*> getCoaches() const;

	void showAthletes(bool onlyActives = false) const;
    
    bool isProgramClub() const;

	void saveChanges();
    string getPathToClubFolder() const;
    string getPathToClubAthletesFile() const;
    string getPathToClubCoachesFile() const;
    string getPathToClubInfoFile() const;

    int findWorkerByCivilID(unsigned int civilID);
    void updateECG(unsigned int athleteID, bool result);
    
    void scheduleMatch(string opponentClub, Date matchDate, Level* level, MatchType type);
    
    //registar jogo já agendado
    void registerMatch(string matchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers);
    
    //registar jogo não agendado
    void registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers);
    
    
    
    
};
