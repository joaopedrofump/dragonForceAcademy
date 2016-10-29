//
//  Defender.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 19/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Defender.hpp"

Defender::Defender(string name, Date birthdate, unsigned char height, unsigned int id) : Athlete(name, birthdate, height, id) {
    
	if (id == 0) {
		this->id = ++Worker::workersCounter;
	}
	else {
		this->id = id;
	}
}


Defender::~Defender() {
    cout << "Defender destroyed" << endl;
}

Position Defender::getPosition() const {
    
    return DefenderPos;
    
}

unsigned int Defender::getID() const{
    
    return this->id;
    
}
