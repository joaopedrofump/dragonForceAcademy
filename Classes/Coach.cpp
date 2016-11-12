#include "Coach.hpp"

Coach::Coach(string name, Date birthdate, unsigned int civilID, CoachType coachRole, unsigned int id) : Worker(name, birthdate, civilID, id) {

	this->trainerPosition = coachRole;

	if (id != 0)
		this->id = id;
}

Coach::Coach(string &newCoach) {

	this->id = stoi(readAndCut(newCoach));
	if (this->id > workersCounter)
		workersCounter = this->id;

	this->civilID = stoi(readAndCut(newCoach));
	this->name = readAndCut(newCoach);
	this->birthdate = Date(readAndCut(newCoach));
	this->trainerPosition = (CoachType)stoi(readAndCut(newCoach));
   

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

string Coach::generateInfo() const {
    
    return (to_string(this->getID()) + " ; " + this->name + " ; " + this->getBirthdate().showDate() + " ; " + to_string(this->trainerPosition));
    
}

vector<string> Coach::showInScreen() const {
    vector<string> result = Worker::showInScreen();
    
    string coachType;
    switch (this->trainerPosition) {
        case HeadCoach:
            coachType = "Head Coach";
            break;
        case GoalkeeperCoach:
            coachType = "Goalkeeper Coach";
            break;
        case PhysicalTrainer:
            coachType = "Physical Trainer";
            break;
    }
    result.push_back(coachType);
    string workerStatus = this->status ? "ACTIVE" : "INACTIVE";
    result.push_back(workerStatus);
    return result;
    
}
