//
//  Midfielder.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Midfielder.hpp"

Midfielder::Midfielder(string name, Date birthdate, unsigned char height, unsigned int id) : Athlete(name, birthdate, height, MidfielderPos, id) {

	if (id == 0) {
		this->id = ++Worker::workersCounter;
	}
	else {
		this->id = id;
	}
}

Midfielder::~Midfielder() {
    
    cout << "Midfielder destroyed\n" << endl;
    
}

Position Midfielder::getPosition() const {
    return MidfielderPos;
    
}

unsigned int Midfielder::getID() const {
    
    return this->id;
    
}
