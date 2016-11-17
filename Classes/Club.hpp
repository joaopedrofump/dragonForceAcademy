#pragma once

#include "Goalkeeper.hpp"
#include "Forward.hpp"

class Season;

extern const map<string, CoachType> coachTypeMap; // coaches' map

class Club {
	string clubName; // club's name
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
	*	This constructor uses the club's name
	*/
	Club(string clubName);

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

	/*!
	*	This is a method that gets the athletes from the workers' map
	*/
	map<unsigned int, Worker*> getAthletes(bool onlyActives = false) const;
	
	/*!
	*	This is a method that gets the inactive players from the workers' map
	*/
	map<unsigned int, Worker*> getInactives() const;

	/*!
	*	This is a method that gets the coaches from the workers' map
	*/
	map<unsigned int, Worker*> getCoaches() const;

	/*!
	*	This is a method that shows all the athletes of the club
	*/
	void showAthletes(bool onlyActives = false) const;

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

};
