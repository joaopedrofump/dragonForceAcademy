#include "Training.hpp"
#include "Club.hpp"

unsigned int Training::trainingCounter = 0;

Training::Training(Date trainingDate, vector<unsigned int> playersIds, unsigned int id) {
    
	if (id == 0) {
		this->id = ++trainingCounter;
	}
	else {
		this->id = id;
	}
    this->trainingDate = trainingDate;
    this->registed = false;
}

Training::Training(istream& iss) {
    
    string separator;
    string date;
    
    iss >> this->id;
    iss >> separator;
    iss >> date;
    this->trainingDate = Date(date);
    iss >> separator;
    iss >> this->registed;
    
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

bool Training::isRegistered() const {
    return this->registed;
}

unsigned int Training::getIdCounter(){
	return trainingCounter;
}

void Training::setPlayers(vector<unsigned int> playersTrained) {
    this->playersTrained = playersTrained;
}

ostream& operator<<(ostream& outStream, Training& trainingToSave) {
    
    outStream << trainingToSave.id << " ; " << trainingToSave.trainingDate << " ; " << trainingToSave.registed;
    
	vector<unsigned int> tmpVector = trainingToSave.getPlayers();
    for (vector<unsigned int>::const_iterator iteratorPlayer = tmpVector.begin() ; iteratorPlayer != tmpVector.end(); iteratorPlayer++) {
        
        outStream << " ; " << *iteratorPlayer;
        
    }
    return outStream;
}

void Training::setRegistered() {
    
    this->registed = true;
    
}

void Training::cancelRegister() {
    
    this->registed = false;
    
}

SortTraining::SortTraining(SortCriteria criteria, SortOrder order){
    this->criteria = criteria;
    this->order = order;
}

bool SortTraining::operator()(Training* t1, Training* t2) {
    
    bool result;
    switch (criteria) {
        case id:
            result = (order == ascending) ? (t1->getId() < t2->getId()) : (t1->getId() > t2->getId());
            break;
        case date:
            result = (order == ascending) ? (t1->getTrainingDate() < t2->getTrainingDate()) : !(t1->getTrainingDate() < t2->getTrainingDate()) ;
            break;
        case numberOfPlayers:
            result = (order == ascending) ? (t1->getPlayers().size() < t2->getPlayers().size()) : !(t1->getPlayers().size() < t2->getPlayers().size()) ;
            break;
            
        default:
            break;
    }
    return result;
}

vector<vector<string>> Training::showInScreen(Club* parentClub) const {

	vector<vector<string>> eachTraining;

	eachTraining.push_back({ to_string(this->getId()), this->getTrainingDate().str(), this->isRegistered() ? "Registed" : "Not Registed" });
	

	if (this->isRegistered()) {

		string players;

		for (size_t j = 0; j < this->getPlayers().size(); j++) {

			players = to_string(this->getPlayers().at(j))
				+ " " + positionsMapPosString.at((Position)parentClub->getAthletes().at(this->getPlayers().at(j))->getPosition())
				+ " " + parentClub->getAthletes().at(this->getPlayers().at(j))->getName();
			
			if (!j)
				eachTraining.at(0).push_back(players);
			else
				eachTraining.push_back({ "","","",players });

		}
		

	}
	else {
		eachTraining.at(0).push_back("No players registered.");
	}
	

	return eachTraining;

}
