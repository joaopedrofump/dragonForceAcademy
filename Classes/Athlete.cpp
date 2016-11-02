//
//  Athlete.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Athlete.hpp"

Athlete::Athlete(string name, Date birthdate, unsigned char height, Position position, unsigned int id) : Worker(name, birthdate, id) {
    
    this->height = height;
    this->ecg = NULL;
	this->position = position;

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


	this->name = newAthleteName;
	this->birthdate = newAthleteBirthdate;
	this->height = newAthleteHeigth;
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