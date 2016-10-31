#include "Club.hpp"

//#include "Season.hpp"
//#include "Level.h"

Club::Club(string name, vector<Season*> seasonsVector) : name(name), seasons(seasonsVector) {}

Club::Club(string fileClub) {

	this->fileName = path() + fileClub + stringPath("/club.txt");

	// =============================
	// ======  Read Coaches  ======
	// =============================

	ifstream inStreamCoaches;

	inStreamCoaches.open(path() + fileClub + stringPath("/coaches.txt").c_str());
	
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

		this->allWorkers.insert(pair<unsigned int, Worker*>(newCoach->getID(), newCoach));

	}

	inStreamCoaches.close();

	// =============================
	// ======  Read Athletes  ======
	// =============================

	ifstream inStreamAthletes;

	inStreamAthletes.open(path() + fileClub + stringPath("/athletes.txt").c_str());

	while (!inStreamAthletes.eof()) {

		string tmpString;
		getline(inStreamAthletes, tmpString);
        
		// Empty file
        if(tmpString.length()==0) {
            continue;
        }

		//Read the last line of file that contains inactive athletes
		if (tmpString == FILE_SEPARATOR) {
			string tmpString;
			getline(inStreamAthletes, tmpString);

			unsigned int athleteId;

			 
			stringstream inactiveClientsStream(tmpString);

			while (!inactiveClientsStream.eof()) {

				inactiveClientsStream >> athleteId;

				if (inactiveClientsStream.fail()) {

					break;

				}

				this->allWorkers.at(athleteId)->setStatus(false);
				

			}
		}

		// Read athlete informations
		unsigned int newAthleteId = atoi(tmpString.substr(0, tmpString.find(';', 0)).c_str());

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		string newAthleteName = tmpString.substr(0, tmpString.find(';', 0));

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		Date newAthleteBirthdate = Date(tmpString.substr(0, tmpString.find(';', 0)));

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);

		unsigned int newAthleteHeigth = atoi(tmpString.substr(0, tmpString.find(';', 0)).c_str());

		tmpString = tmpString.substr(tmpString.find(';', 0) + 2);


		Position newAthletePosition = positionsMap.at(tmpString);

		Worker* newAthlete = 0;

		if (newAthletePosition == GoalkeeperPos) {
			newAthlete = new Goalkeeper(newAthleteName, newAthleteBirthdate, newAthleteHeigth, newAthleteId);
		}
		else if (newAthletePosition == DefenderPos) {
			newAthlete = new Defender(newAthleteName, newAthleteBirthdate, newAthleteHeigth, newAthleteId);
		}
		else if (newAthletePosition == MidfielderPos) {
			newAthlete = new Midfielder(newAthleteName, newAthleteBirthdate, newAthleteHeigth, newAthleteId);
		}
		/*else if (newAthletePosition == ForwardPos) {
			newAthlete = new Forward(newAthleteName, newAthleteBirthdate, newAthleteHeigth, newAthleteId);
		}*/

		this->allWorkers.insert(pair<unsigned int, Worker*>(newAthlete->getID(), newAthlete));

	}

	inStreamAthletes.close();

	// ===========================================
	// ===== Read informations from fileClub  ====
	// ===========================================

	ifstream inStreamClub;

	inStreamClub.open(path() + fileName.c_str());

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
        
		Season* actualSeason = new Season(seasonName, path() + fileClub);

		this->seasons.push_back(actualSeason);
	}

	this->numberOfSeasons = (int)seasons.size();


}

string Club::getName() const {
	return name;
}

map<unsigned int, Worker*> Club::getWorkers() const {
	return allWorkers;
}

vector<Season*> Club::getSeasons() const {
	return seasons;
}

map<unsigned int, Worker*> Club::getAthletes() const {

	map<unsigned int, Worker*> result;

	for (size_t i = 0; i < getWorkers().size(); i++) {

		if (getWorkers().at(i)->isAthlete()) {
			result.insert(pair<unsigned int, Worker*>(getWorkers().at(i)->getID(), getWorkers().at(i)));
		}
	}

	return result;
}

map<unsigned int, Worker*> Club::getCoaches() const {

	map<unsigned int, Worker*> result;

	for (size_t i = 0; i < getWorkers().size(); i++) {

		if (!getWorkers().at(i)->isAthlete()) {
			result.insert(pair<unsigned int, Worker*>(getWorkers().at(i)->getID(), getWorkers().at(i)));
		}
	}

	return result;
}


