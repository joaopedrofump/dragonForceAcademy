#include "Coach.hpp"

Coach::Coach(string name, Date birthdate, unsigned int civilID, CoachType coachRole, unsigned int id) : Worker(name, birthdate, civilID, id) {

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
    
    newCoach = newCoach.substr(newCoach.find(';', 0) + 2);
    
    unsigned int newCoachCivilID = stoi(newCoach);

	this->id = newCoachId;
	this->name = newCoachName;
	this->birthdate = newCoachBirthdate;
	this->trainerPosition = newCoachPosition;
    this->civilID = newCoachCivilID;

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
            coachType = "HeadCoach";
            break;
        case GoalkeeperCoach:
            coachType = "Defender";
            break;
        case PhysicalTrainer:
            coachType = "Physio";
            break;
        case AssistantCoach:
            coachType = "Assistant";
            break;
    }
    result.push_back(coachType);
    string workerStatus = this->status ? "ACTIVE" : "INACTIVE";
    result.push_back(workerStatus);
    return result;
    
}
