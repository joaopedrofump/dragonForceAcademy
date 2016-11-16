#pragma once

#include "Goalkeeper.hpp"

class Season;
class Match;
class Level;

extern const map<string, CoachType> coachTypeMap;
extern const map<string, ageLevel> ageLevelMap;

extern bool confirm(const Table &message);

extern void showMainMenu(unsigned short int optionChosen, string seasonName);

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
	bool reativateAthlete(unsigned int athleteId);
    void editPlayer(unsigned int athleteId, string newName, Date newBirthDate, unsigned int newHeight, unsigned int newCivilID);

	map<unsigned int, Worker*> getAthletes(bool onlyActives = false) const;
	map<unsigned int, Worker*> getInactives(unsigned char workersType = 0) const;
	map<unsigned int, Worker*> getCoaches(bool onlyActives = false) const;

	void showAthletes(bool onlyActives = false) const;
	bool showAthlete(unsigned int id) const;
	void showAthletesInactives() const;

	void addCoach(CoachType position, string name, Date birthdate, unsigned int civilID, ageLevel level, bool mainCoach = false);
	bool removeCoach(unsigned int coachId);
	bool reativateCoach(unsigned int coachId);
	void showCoaches(bool onlyActives = false) const;
	void showCoachesInactives() const;
    void editCoach(unsigned int coachId, string newName, Date newBirthDate, unsigned int newCivilID, unsigned int newCoachType);

    bool isProgramClub() const;

	void saveChanges();
    string getPathToClubFolder() const;
    string getPathToClubAthletesFile() const;
    string getPathToClubCoachesFile() const;
    string getPathToClubInfoFile() const;

    int findWorkerByCivilID(unsigned int civilID);
    void updateECG(unsigned int athleteID, bool result);
    
    void scheduleMatch(string opponentClub, Date matchDate, Level* level, MatchType type);
    
    //convocar jogadores para jogo agendado
    void callUpPlayers(string matchId, vector<unsigned int> matchPlayers, Level* level);
    
    //convocar jogadores para jogo não agendado
    void callUpPlayers(string opponentClub, Date matchDate, Level* level, MatchType type, vector<unsigned int> matchPlayers);
    
    //registar jogo já agendado com performance de jogadores (para mais tarde)
    void registerMatch(string matchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers);
    
    //registar jogo não agendado com performance de jogadores (para mais tarde)
    void registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, map<unsigned int, Info*> matchPlayers);
    
    //registar jogo já agendado sem performance de jogadores (para já)
    void registerMatch(string matchId, Level* level, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers);
    
    //registar jogo não agendado sem performance de jogadores (para já)
    void registerMatch(string opponentClub, Date matchDate, Level* level, MatchType type, unsigned int homeTeamScore, unsigned int awayTeamScore, vector<unsigned int> matchPlayers);
    
    
    void scheduleTraining(Date trainingDate, Level* level);
    
    //registar treino já agendado
    void registerTraining(unsigned int trainingId, Level* level, vector<unsigned int> missingPlayers);
    
    //registar treino não agendado
    void registerTraining(Date trainingDate, Level* level, vector<unsigned int> missingPlayers);
    
    
};
