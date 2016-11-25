//
//  Worker.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Worker.hpp"

unsigned int Worker::workersCounter = 0;

Worker::Worker(string name, Date birthdate, unsigned int civilID, unsigned int id) {
    
    if(to_string(civilID).length() != 8) {
        throw string("Invalid Civil ID");
    }
    
    if(!validateName(name)) {
        throw string("Invalid Name");
    }
    
    this->name = name;
    this->birthdate = birthdate;
	this->status = true;
    this->civilID = civilID;
    

	if (id == 0) {
		this->id = ++workersCounter;
	}
	else {
		this->id = id;
	}
    
}

Worker::Worker() {
	this->status = true;
}

Worker::~Worker() {
    
    cout << "Worker Destroyed\n" << endl;
}

unsigned int Worker::getID() const{
	return this->id;
}

bool Worker::operator==(Worker* worker) const {

	if (this->getID() == worker->getID())
		return true;
	return false;
}

void Worker::setId(unsigned int newId) {

	this->id = newId;

	if (newId > workersCounter)
		workersCounter = newId;

}

void Worker::setCivilId(unsigned int newCivilId) {
    
    this->civilID = newCivilId;
    
}

void Worker::setStatus(bool newStatus) {

	this->status = newStatus;

}

unsigned int Worker::getAge() const {
	
    return Date() - this->birthdate;

}

Date Worker::getBirthdate() const {
    
     return this->birthdate;
    
}

string Worker::getName() const {
	return this->name;
}

unsigned int Worker::getLastId() {

	return Worker::workersCounter;

}

ostream& operator<<(ostream& out, const Worker &worker) {
    
    out << worker.generateInfo();
    return out;
    
}

vector<string> Worker::showInScreen() const {
    
    vector<string>output;
    output.push_back(to_string(this->id));
    output.push_back(to_string(this->civilID));
    output.push_back(this->name);
    output.push_back(this->birthdate.showDate());
    output.push_back(to_string(this->getAge()));
    return output;
    
}

unsigned int Worker::getCivilID() const {
    return this->civilID;
}

bool Worker::isActive()const {
    return this->status;
}

void Worker::updateECG(bool resultado, Date expirationDate) {}

ECG* Worker::getECG() const { return NULL; }

void Worker::setName(string newName) {
    
    if(!validateName(newName)) {
        throw string("Invalid Name");
    }
    this->name = newName;
    
}
SortWorker::SortWorker(SortCriteria criteria, SortOrder order) {
    this->criteria = criteria;
    this->order = order;
    
}
bool SortWorker::operator()(Worker* t1, Worker* t2) const {
    
    if(t1->isAthlete() && !t2->isAthlete()) { //athlete vs coach
        return true;
    }
    else if (!t1->isAthlete() && t2->isAthlete()) { //coach vs athlete
        return false;
    }
    
    else if(t1->isAthlete() && t2->isAthlete()) { //two athletes
        
        switch (criteria) {
            case playerPosition:
                if (this->order == ascending) {
                    if(t1->getPosition() != t2->getPosition()) {
                        return t1->getPosition() < t2->getPosition();
                    }
                    return t1->getName() < t2->getName();
                    
                }
                if(t1->getPosition() != t2->getPosition()) {
                    return t1->getPosition() > t2->getPosition();
                }
                return t1->getName() < t2->getName();
                break;
            case name:
                if (this->order == ascending) {
                    return t1->getName() <= t2->getName();
                }
                return t1->getName() > t2->getName();
                break;
            case age:
                if (this->order == ascending) {
                    return t1->getAge() <= t2->getAge();
                }
                return t1->getAge() > t2->getAge();
                break;
            case height:
                if (this->order == ascending) {
                    return t1->getHeight() <= t2->getHeight();
                }
                return t1->getHeight() > t2->getHeight();
                break;
            case ecg:
                if (this->order == ascending) {
                    if(!t1->getECG() && t2->getECG()) {
                        return true;
                    }
                    else if(t1->getECG() && !t2->getECG()){
                        return false;
                    }
                    else if(t1->getECG() && t2->getECG()) {
                        
                        if (!t1->getECG()->getResultado() && t2->getECG()->getResultado()) {
                            return true;
                        }
                        else if(t1->getECG()->getResultado() && !t2->getECG()->getResultado()) {
                            return false;
                        }
                        else if(t1->getECG()->getResultado() && t2->getECG()->getResultado()) {
                            return t1->getECG()->getExpirationDate() < t2->getECG()->getExpirationDate();
                        }
                        
                    }
                }
                if(!t1->getECG() && t2->getECG()) {
                    return false;
                }
                else if(t1->getECG() && !t2->getECG()){
                    return true;
                }
                else if(t1->getECG() && t2->getECG()) {
                    
                    if (!t1->getECG()->getResultado() && t2->getECG()->getResultado()) {
                        return false;
                    }
                    else if(t1->getECG()->getResultado() && !t2->getECG()->getResultado()) {
                        return true;
                    }
                    else if(t1->getECG()->getResultado() && t2->getECG()->getResultado()) {
                        return !(t1->getECG()->getExpirationDate() < t2->getECG()->getExpirationDate());
                    }
                    
                }
                
                break;
                
            default:
                break;
        }
        
    }
    
    else {
        
        switch (criteria) {
            case typeOfCoach:
                if (this->order == ascending) {
                    if(t1->getPosition() != t2->getPosition()) {
                        return t1->getPosition() < t2->getPosition();
                    }
                    return t1->getName() < t2->getName();
                    
                }
                if(t1->getPosition() != t2->getPosition()) {
                    return t1->getPosition() > t2->getPosition();
                }
                return t1->getName() < t2->getName();
                break;
            case name:
                if (this->order == ascending) {
                    return t1->getName() <= t2->getName();
                }
                return t1->getName() > t2->getName();
                break;
            case age:
                if (this->order == ascending) {
                    return t1->getAge() <= t2->getAge();
                }
                return t1->getAge() > t2->getAge();
                break;
            
            default:
                break;
        }

        
    }
    
    
    return true;
    
}
