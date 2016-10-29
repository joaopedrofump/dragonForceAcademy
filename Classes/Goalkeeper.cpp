//
//  Goalkeeper.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Goalkeeper.hpp"

Goalkeeper::Goalkeeper(string name, Date birthdate, unsigned char height, unsigned int id) : Athlete(name, birthdate, height, id) {
    
    this->goalsConceded = 0;
    this->saves = 0;

	if (id == 0) {
		this->id = ++Worker::workersCounter;
	}
	else {
		this->id = id;
	}
    
    
}


Goalkeeper::~Goalkeeper() {
    cout << "Goalkeeper destroyed\n" << endl;
}


Position Goalkeeper::getPosition() const {
    
    return GoalkeeperPos;
    
}

unsigned int Goalkeeper::getID() const {
    
    return this->id;

}
