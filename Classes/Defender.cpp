//
//  Defender.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 19/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Defender.hpp"

Defender::Defender(string name, Date birthdate, unsigned char height, DefenderPosition detailedPosition) : Athlete(name, birthdate, height) {
    
    this->id = ++Worker::workersCounter;
    this->detailedPosition = detailedPosition;
    
}

Defender::~Defender() {
    cout << "Defender destroyed" << endl;
}

Position Defender::getPosition() const {
    
    return DefenderPos;
    
}

unsigned int Defender::getID() {
    
    return this->id;
    
}
