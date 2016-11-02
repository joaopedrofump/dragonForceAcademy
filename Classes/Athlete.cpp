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

	if (id == 0) {
		this->id = ++Worker::workersCounter;
	}
	else {
		this->id = id;
	}
    
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
unsigned char Athlete::getHeight() const {
	return height;
}
