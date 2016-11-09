#pragma once

#include "Goalkeeper.hpp"

class Season;

extern const map<string, CoachType> coachTypeMap;

class Club {
	string clubName;
	map<unsigned int, Worker*> allWorkers;
	vector<Season*> seasons;
	unsigned int numberOfSeasons;
    string pathToClubFolder;
    string pathToClubAthletesFile;
    string pathToClubCoachesFile;
    string pathToClubInfoFile;


public:
	Club(string clubName);

	string getName() const;
	map<unsigned int, Worker*> getWorkers() const;
	vector<Season*> getSeasons() const;

	void addPlayer(Position pos, string name, Date birthdate, unsigned int civilID, unsigned char height);
	bool removeAthlete(unsigned int athleteId);

	map<unsigned int, Worker*> getAthletes(bool onlyActives = false) const;
	map<unsigned int, Worker*> getInactives() const;
	map<unsigned int, Worker*> getCoaches() const;

	void showAthletes(bool onlyActives = false) const;

	void saveChanges();
    string getPathToClubFolder() const;
    string getPathToClubAthletesFile() const;
    string getPathToClubCoachesFile() const;
    string getPathToClubInfoFile() const;

    int findWorkerByCivilID(unsigned int civilID);
    void updateECG(unsigned int athleteID, bool result);

};
