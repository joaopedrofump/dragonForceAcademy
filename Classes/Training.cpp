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
    
    string separator;
    string date;
    
    iss >> this->id;
    iss >> separator;
    iss >> date;
    this->trainingDate = Date(date);
    
    while (!iss.eof()) {
        
        unsigned int currentPlayerId;
        iss >> separator;
        iss >> currentPlayerId;
        this->playersTrained.push_back(currentPlayerId);
        
    }
    
    Training::trainingCounter = this->id > Training::trainingCounter ? this->id : Training::trainingCounter;
    
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

bool Training::getTrainingGiven() const {
    
    return this->playersTrained.size() != 0;
    
}

void Training::setPlayers(vector<unsigned int> playersTrained) {
    this->playersTrained = playersTrained;
}

ostream& operator<<(ostream& outStream, Training& trainingToSave) {
    
    outStream << trainingToSave.id << " ; " << trainingToSave.trainingDate;
    
    for (vector<unsigned int>::const_iterator iteratorPlayer = trainingToSave.getPlayers().begin() ; iteratorPlayer != trainingToSave.getPlayers().end(); iteratorPlayer++) {
        
        outStream << " ; " << *iteratorPlayer;
        
    }
    return outStream;
}
