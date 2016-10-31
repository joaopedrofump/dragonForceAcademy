#include "Club.hpp"

#include "Season.hpp"
#include "Level.h"

Club::Club(string name, vector<Season*> seasonsVector) : name(name), seasons(seasonsVector) {}

Club::Club(string fileClub) {

	this->fileName = fileClub + stringPath("/club.txt");

	// =============================
	// ======  Read Coaches  ======
	// =============================

	ifstream inStreamCoaches;

	inStreamCoaches.open(fileClub + stringPath("/coaches.txt").c_str());
	
	while (!inStreamCoaches.eof()) {

		string tmpString;
		getline(inStreamCoaches, tmpString);
        
        if(tmpString.length()==0) {
            continue;
        }

		unsigned int newCoachId = atoi(tmpString.substr(0, tmpString.find(';', 0)).c_str());

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		string newCoachName = tmpString.substr(0, tmpString.find(';', 0));

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		Date newCoachBirthdate = Date(tmpString.substr(0, tmpString.find(';', 0)));

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		CoachType newCoachPosition = coachTypeMap.at(tmpString);


		Worker* newCoach = new Coach(newCoachName, newCoachBirthdate, newCoachPosition, newCoachId);

		this->allWokers.push_back(newCoach);

	}

	inStreamCoaches.close();

	// =============================
	// ======  Read Athletes  ======
	// =============================

	ifstream inStreamAthletes;

	inStreamAthletes.open(fileClub + stringPath("/athletes.txt").c_str());

	while (!inStreamAthletes.eof()) {

		string tmpString;
		getline(inStreamAthletes, tmpString);
        
        if(tmpString.length()==0) {
            continue;
        }

		unsigned int newAthleteId = atoi(tmpString.substr(0, tmpString.find(';', 0)).c_str());

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		string newAthleteName = tmpString.substr(0, tmpString.find(';', 0));

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		Date newAthleteBirthdate = Date(tmpString.substr(0, tmpString.find(';', 0)));

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		unsigned int newAthleteHeigth = atoi(tmpString.substr(0, tmpString.find(';', 0)).c_str());

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);


		Position newAthletePosition = positionsMap.at(tmpString);

		Worker* newAthlete;

		if (newAthletePosition == GoalkeeperPos) {
			newAthlete = new Goalkeeper(newAthleteName, newAthleteBirthdate, newAthleteHeigth, newAthleteId);
		}
		else if (newAthletePosition == DefenderPos) {
			newAthlete = new Defender(newAthleteName, newAthleteBirthdate, newAthleteHeigth, newAthleteId);
		}
		else if (newAthletePosition == MidfielderPos) {
			newAthlete = new Midfielder(newAthleteName, newAthleteBirthdate, newAthleteHeigth, newAthleteId);
		}

		this->allWokers.push_back(newAthlete);

	}

	inStreamAthletes.close();

	// ===========================================
	// ===== Read informations from fileClub  ====
	// ===========================================

	ifstream inStreamClub;

	inStreamClub.open(this->fileName.c_str());

	// Read the Name of the Club

	if (!inStreamClub.eof()) {
		getline(inStreamClub, this->name);
	}

	while (!inStreamClub.eof()) {
        
        string seasonName;
        getline(inStreamClub, seasonName);
        
        if(seasonName.length() == 0) {
            continue;
        }
        
		Season* actualSeason = new Season(seasonName, fileClub, this);

		this->seasons.push_back(actualSeason);
	}

	this->numberOfSeasons = (int)seasons.size();


}

string Club::getName() const {
	return name;
}

vector<Worker*> Club::getWorkers() const {
	return allWokers;
}

vector<Season*> Club::getSeasons() const {
	return seasons;
}


