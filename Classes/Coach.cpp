#include "Coach.hpp"

Coach::Coach(string name, Date birthdate, CoachType coachRole, unsigned int id) : Worker(name, birthdate, id) {

	this->trainerPosition = coachRole;

	if (id == 0)
		this->id = ++workersCounter;
	else
		this->id = id;
}

Coach::Coach(string &newCoach) {

	unsigned int newCoachId = atoi(newCoach.substr(0, newCoach.find(';', 0)).c_str());

	newCoach = newCoach.substr(newCoach.find(';', 0) + 2);

	string newCoachName = newCoach.substr(0, newCoach.find(';', 0));

	newCoach = newCoach.substr(newCoach.find(';', 0) + 2);

	Date newCoachBirthdate = Date(newCoach.substr(0, newCoach.find(';', 0)));

	newCoach = newCoach.substr(newCoach.find(';', 0) + 2);

	CoachType newCoachPosition = coachTypeMap.at(newCoach);

	this->id = newCoachId;
	this->name = newCoachName;
	this->birthdate = newCoachBirthdate;
	this->trainerPosition = newCoachPosition;

}

unsigned int Coach::getID() const {
	return this->id;
}

bool Coach::isAthlete() const {

	return false;
}

unsigned int Coach::getPosition() const {
	return this->trainerPosition;
}

unsigned int Coach::getHeight() const {
	return 0;
}