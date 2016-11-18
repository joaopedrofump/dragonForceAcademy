#pragma once

#include "Goalkeeper.hpp"
#include "Forward.hpp"

class Season;
class Match;
class Level;

extern const map<string, CoachType> coachTypeMap; // coaches' map
extern const map<string, ageLevel> ageLevelMap; // ageLevels' map

extern bool confirm(const Table &message);

extern void showMainMenu(unsigned short int optionChosen, string seasonName);

class Club {
	string clubName; // club's name
	bool programClub; //  TRUE if the club is the program Club
	map<unsigned int, Worker*> allWorkers;  // workers' map
	vector<Season*> seasons; // vector that includes all played season
	unsigned int numberOfSeasons; //number of seasons played
	string pathToClubFolder; //path to the club's folder
	string pathToClubAthletesFile; //path to the athletes' file
	string pathToClubCoachesFile; //path to the coaches' file
	string pathToClubInfoFile; //path to the club's info file


public:
	//! Club's constructor
	/*!
	*	This constructor uses the club's name and empty to not program clubs
	*/
	Club(string clubName, bool empty = false);

	/*!
	*	This is a method that gets the club's name
	*/
	string getName() const;

	/*!
		This is a method that gets the workers' map
	*/
	map<unsigned int, Worker*> getWorkers() const;
	
	/*!
	*	This is a method that gets the seasons' vector
	*/
	vector<Season*> getSeasons() const;
	
	/*!
	*	This is a method taht adds a player to the club, putting the player in the respective season and level
	*/
	void addPlayer(Position pos, string name, Date birthdate, unsigned char height);

	/*!
	*	This is a method that adds a player to the club, putting the player in the respective season and level
	*/
	void addPlayer(Position pos, string name, Date birthdate, unsigned int civilID, unsigned char height);
	
	/*!
	*	This is a method that checks if the player exists and removes him
	*/
	bool removeAthlete(unsigned int athleteId);
	bool reativateAthlete(unsigned int athleteId);
    void editPlayer(unsigned int athleteId, string newName, Date newBirthDate, unsigned int newHeight, unsigned int newCivilID);

	/*!
	*	This is a method that gets the athletes from the workers' map
	*/
	map<unsigned int, Worker*> getAthletes(bool onlyActives = false) const;

	// FAZER DOXYGEN
	map<unsigned int, Worker*> getInactives(unsigned char workersType = 0) const;
	map<unsigned int, Worker*> getCoaches(bool onlyActives = false) const;
	
	/*!
	*	This is a method that gets the inactive players from the workers' map
	*/
	//map<unsigned int, Worker*> getInactives() const;

	/*!
	*	This is a method that gets the coaches from the workers' map
	*/
	//map<unsigned int, Worker*> getCoaches() const;

	/*!
	*	This is a method that shows all the athletes of the club
	*/
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

	/*!
	*	This is a method that saves the changes made by the user
	*/
	void saveChanges();
    
	/*!
	*	This is a method that gets the path to the club's folder
	*/
	string getPathToClubFolder() const;
    
	/*!
	*	This is a method that gets the path to the athletes' file
	*/
	string getPathToClubAthletesFile() const;
    
	/*!
	*	This is a method that gets the path to the coaches' file
	*/
	string getPathToClubCoachesFile() const;
    
	/*!
	*	This is a method that gets the path to the club's info file
	*/
	string getPathToClubInfoFile() const;
	/*!
	*	This is a method that finds a worker by civilID
	*/
	int findWorkerByCivilID(unsigned int civilID);

	/*!
	*	This is a method that updates the athlete's ECG
	*/
	void updateECG(unsigned int athleteID, bool result);

	// FAZER DOXYGEN

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

    
};
