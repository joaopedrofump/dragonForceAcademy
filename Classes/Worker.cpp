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
