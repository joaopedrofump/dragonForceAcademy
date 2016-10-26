#include "Trainer.hpp"

Trainer::Trainer(string name, Date birthdate, Position trainerPosition) : Worker(name, birthdate) {

	this->trainerPosition = trainerPosition;
}

unsigned int Trainer::getID() const {
	return this->id;
}