//
//  Athlete.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Athlete.hpp"

Athlete::Athlete(string name, Date birthdate, unsigned int civilID, unsigned char height, unsigned int id) : Worker(name, birthdate, civilID, id) {
    
    this->height = height;
    this->ecg = NULL;

	if (id != 0) {
        this->id = id;
    }
}

Athlete::Athlete(string &newAthlete, Position position) : position(position) {

	string newAthleteName = newAthlete.substr(0, newAthlete.find(';', 0));

	newAthlete = newAthlete.substr(newAthlete.find(';', 0) + 2);

	Date newAthleteBirthdate = Date(newAthlete.substr(0, newAthlete.find(';', 0)));

	newAthlete = newAthlete.substr(newAthlete.find(';', 0) + 2);

	unsigned int newAthleteHeigth = atoi(newAthlete.c_str());
    
    newAthlete = newAthlete.substr(newAthlete.find(';', 0) + 2);
    
    unsigned int newAthleteCivilID = stoi(newAthlete);


	this->name = newAthleteName;
	this->birthdate = newAthleteBirthdate;
	this->height = newAthleteHeigth;
    this->civilID = newAthleteCivilID;
    this->status = true;
}



Athlete::~Athlete() {
    
    if(this->ecg) {
        delete this->ecg;
    }
    cout << "Athlete Destroyed\n";
    
}

void Athlete::addECG(bool resultado) {
    
    this->ecg = new ECG(resultado);
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
    return result;
    
}
