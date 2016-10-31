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