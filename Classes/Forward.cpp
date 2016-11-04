#include "Forward.hpp"

Forward::Forward(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int id) : Athlete(name, birthdate, civilID, height, id) {
    
    if (id != 0) {
        this->id = id;
    }
    
    this->position = ForwardPos;
    this->generalInfo = new InfoFW();
}

Forward::Forward(string &newFW) : Athlete(newFW, ForwardPos) {
    
    this->generalInfo = new InfoFW();
}

Forward::~Forward() {
	delete this->generalInfo;
	cout << "Forward destroyed\n" << endl;
}

unsigned int Forward::getID() const {
    
	return this->id;
}

Info* Forward::getInfo() const {
    
    return this->generalInfo;
}

void Forward::addInfo(Info* moreInfo) {
    
    *(this->generalInfo) += moreInfo;
    
}
