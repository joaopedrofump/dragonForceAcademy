//
//  Athlete.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Athlete.hpp"

Athlete::Athlete(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int id) : Worker(name, birthdate, civilID, id) {
    

    if(Date()-birthdate < 11 || Date() - birthdate > 45) {
        throw string("Invalid Age");
    }
    
    if(height < 100 || height > 250) {
        throw string("Invalid Height");
    }
    
    this->height = height;
    this->ecg = NULL;

	if (id != 0) {
        this->id = id;
    }
}

Athlete::Athlete(string &newAthlete, Position position) : position(position) {

	this->name = readAndCut(newAthlete);
    this->ecg = NULL;
	this->birthdate = Date(readAndCut(newAthlete));
	this->height = stoi(readAndCut(newAthlete));

	if(newAthlete != "NONE")
		this->ecg = new ECG(readAndCut(newAthlete) == "VALID" ? true : false, Date(readAndCut(newAthlete)));
    
}



Athlete::~Athlete() {
    
    if(this->ecg) {
        delete this->ecg;
    }
    cout << "Athlete Destroyed\n";
    
}

void Athlete::updateECG(bool resultado, Date expirationDate) {
    
    ECG* tmpECG = 0;
    try {
        tmpECG = new ECG(resultado, expirationDate);
    } catch (...) {
        cout << "error adding new ECG, ECG invalid" << endl;
    }
    
    if(!this->ecg) {
        this->ecg = tmpECG;
    }
    else {
        delete this->ecg;
        this->ecg = tmpECG;
    }
    
}

bool Athlete::isAthlete() const {

	return true;

}

unsigned int Athlete::getPosition() const {
	return position;
}

unsigned int Athlete::getHeight() const {
	return height;
}

ECG* Athlete::getECG() const {
	return this->ecg;
}

string Athlete::generateInfo() const {
    
    return (to_string(this->getID()) + " ; " + to_string(this->getPosition()) + " ; " + this->name + " ; " + this->getBirthdate().showDate() + " ; " + to_string(this->height));
    
}

vector<string> Athlete::showInScreen() const {
    vector<string> result = Worker::showInScreen();
    
    string playerHeight = to_string((float)this->height/100);
    string playerHeightFinal;
    for (size_t i = 0; i < 4; i++) {
        playerHeightFinal+=playerHeight.at(i);
    }
    
    result.push_back(playerHeightFinal + " m");
    string playerPosition;
    switch (this->position) {
        case GoalkeeperPos:
            playerPosition = "GoalKeeper";
            break;
        case DefenderPos:
            playerPosition = "Defender";
            break;
        case MidfielderPos:
            playerPosition = "Midfielder";
            break;
        case ForwardPos:
            playerPosition = "Forward";
            break;
    }
    result.push_back(playerPosition);

    result.push_back(getLevelFromAge(this->birthdate));

    string workerStatus = this->status ? "ACTIVE" : "INACTIVE";
    result.push_back(workerStatus);

	if (this->getECG())
		result.push_back(this->getECG()->showInScreen());
	else
		result.push_back("NONE");

	return result;
    
}

void Athlete::setBirthDate(Date newBirthdate) {
    

    if(Date()-birthdate < 11 || Date() - birthdate > 45) {
        throw string("Invalid Age");
    }

    this->birthdate = newBirthdate;
    
}

void Athlete::setHeight(unsigned int newHeight) {
    
    if(height < 100 || height > 250) {
        throw string("Invalid Height");
    }
    this->height= newHeight;
}


