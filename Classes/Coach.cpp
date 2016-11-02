#include "Coach.hpp"

Coach::Coach(string name, Date birthdate, CoachType coachRole, unsigned int id) : Worker(name, birthdate, id) {

	this->trainerPosition = coachRole;

	if (id == 0)
		this->id = ++workersCounter;
	else
		this->id = id;
}

unsigned int Coach::getID() const {
	return this->id;
}

bool Coach::isAthlete() const {

	return false;
}

string Coach::generateInfo() const {
    
    return (to_string(this->getID()) + " ; " + this->name + " ; " + this->getBirthdate().showDate() + " ; " + to_string(this->trainerPosition));
    
}
