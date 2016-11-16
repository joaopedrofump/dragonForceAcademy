#include "Training.hpp"

unsigned int Training::trainingCounter = 0;

Training::Training(Date trainingDate, vector<unsigned int> playersIds, unsigned int id) {
    
	if (id == 0) {
		this->id = ++trainingCounter;
	}
	else {
		this->id = id;
	}
	this->trainingDate = trainingDate;
}

Training::Training(istream& iss) {
    
}

void Training::resetID(unsigned int newId) {
    Training::trainingCounter = newId;
}

Date Training::getTrainingDate() const {
	return this->trainingDate;
}

unsigned int Training::getId() const {
	return this->id;
}

vector<unsigned int> Training::getPlayers() const {
    return this->playersTrained;
    
}

void Training::setPlayers(vector<unsigned int> playersTrained) {
    this->playersTrained = playersTrained;
}
