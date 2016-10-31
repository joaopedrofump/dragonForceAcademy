#include "Club.hpp"

#include "Season.hpp"
#include "Level.h"

Club::Club(string name, vector<Season*> seasonsVector) : name(name), seasons(seasonsVector) {}

Club::Club(string fileClub) {

	this->fileName = fileClub + "\\club.txt";

	// =============================
	// ======  Read Coaches  ======
	// =============================

	ifstream inStreamCoaches;

	inStreamCoaches.open(fileClub + string("\\Coaches.txt").c_str());
	
	while (!inStreamCoaches.eof()) {

		string tmpString;
		getline(inStreamCoaches, tmpString);

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

	inStreamAthletes.open(fileClub + string("\\Athletes.txt").c_str());

	while (!inStreamAthletes.eof()) {

		string tmpString;
		getline(inStreamAthletes, tmpString);

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
		
		Season* actualSeason = new Season(inStreamClub, fileClub, this);

		this->seasons.push_back(actualSeason);
	}

	this->numberOfSeasons = seasons.size();


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

void Club::addPlayer(Position pos, string name, Date birthdate, unsigned char height)
{
	Date currentDate(true);
	Season* currentSeason;
	Athlete* w;

	try
	{
		if (pos == 1)
		{
			w = new Goalkeeper(name, birthdate, height);
			
		}
		else if (pos == 2)
		{
			w = new Defender(name, birthdate, height);
		
		}
		else if (pos == 3)
		{
			w = new Midfielder(name, birthdate, height);
		}
		else if (pos == 4)
		{
			Worker* w = new Forward(name, birthdate, height);
		}
		
		allWokers.push_back(w);

		for (unsigned int i = 0; i < seasons.size(); i++)
		{
			if (currentDate.getYear() == seasons.at(i)->getYear())
			{
				Season* currentSeason;
				seasons.at(i) = currentSeason;
				break;
			}
		}

		for (unsigned int i = 0; i < currentSeason->getLevels().size(); i++)
		{
			if (w->getIdade() > currentSeason->getLevels().at(i)->getMinAge() && w->getIdade() < currentSeason->getLevels().at(i)->getMaxAge())
			{
				if (w->getHeight() < currentSeason->getLevels().at(i)->getMinHeight())
				{

				}
			}
		}
	
	}
	catch (/*to be completed*/)
	{
		
	}

}


