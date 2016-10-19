//
//  Goalkeeper.cpp
//  DragonForceAcadamy
//
//  Created by Joao Furriel on 13/10/16.
//  Copyright © 2016 João Furriel Pinheiro. All rights reserved.
//

#include "Goalkeeper.hpp"

Goalkeeper::Goalkeeper(string name, Date birthdate, unsigned char height) : Athlete(name, birthdate, height) {
    
    this->goalsConceded = 0;
    this->saves = 0;
    this->id = ++Worker::workersCounter;
    
}

Position Goalkeeper::getPosition() const {
    
    return GoalkeeperPos;
    
}

unsigned int Goalkeeper::getID() const {
    
    return this->id;

}
