//
//  Midfielder.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 20/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Midfielder.hpp"

Midfielder::Midfielder(string name, Date birthdate, unsigned char height, MidfielderPosition detailedPosition) : Athlete(name, birthdate, height) {
    this->id = ++Worker::workersCounter;
    this->detailedPosition = detailedPosition;
}

Midfielder::~Midfielder() {
    
    cout << "Midfielder destroyed\n" << endl;
    
}

Position Midfielder::getPosition() const {
    return DefenderPos;
    
}

unsigned int Midfielder::getID() const {
    
    return this->id;
    
}
