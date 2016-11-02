//
//  Athlete.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 12/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Athlete.hpp"

Athlete::Athlete(string name, Date birthdate, unsigned char height, unsigned int id) : Worker(name, birthdate, id) {
    
    this->height = height;
    this->ecg = NULL;

	if (id != 0) {
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

string Athlete::generateInfo() const {
    
    return (to_string(this->getID()) + " ; " + to_string(this->getPosition()) + " ; " + this->name + " ; " + this->getBirthdate().showDate() + " ; " + to_string(this->height));
    
}
